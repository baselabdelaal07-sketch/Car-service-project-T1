#include "Center.h"
#include"Car.h"
#include"IDLE_LIST.h"
#include <cstdlib>
void Center::GenerateCars(int n) {
    int vt = 1;
    for (int i = 1; i <= n; i++) {
        vt += rand() % 3;                  
        int pt = vt + (rand() % 11) - 5;   
        if (pt < 1) pt = 1;
        int dd = 1 + rand() % 5;           

        Car* c = new Car(i, vt, pt , dd);
        c->setCarStatus(CarStatus::IDLE);
        idle.enqueue(c);
    }
}
void Center::DistributeFromIdle() {
  
    Car* c;
    for (int i = 0; i < 50; i++) { // eb2a 3ayar el 50 to a varibale f phase 2 
        if (!idle.dequeue(c)) break;          

        int r = rand() % 3;                  //r hyb2a o aw 1 aw 2 f htb2a even random distribution rather than using 50 
        if (r == 0) {
            c->setCarStatus(CarStatus::ERLY);
            erly.enqueue(c, c->getPT());
        }
        else if (r == 1) {
            c->setCarStatus(CarStatus::REDY);
            ready.enqueue(c);
        }
        else {
            c->setCarStatus(CarStatus::LATE);
            late.enqueue(c);
        }
    }
}

void Center::MoveErlyToRedy() {
    Car* c;
    int pri;
    for (int i = 0; i < 6; i++) {
        if (!erly.dequeue(c, pri)) break;   
        c->setCarStatus(CarStatus::REDY);
        ready.enqueue(c);
    }
}
void Center::CancelFromLate(int timestep) {
    if (rand() % 100 < 10) {
        Car* c;
        if (late.CancelRandomCar(c)) {
            c->setCarStatus(CarStatus::CNCL);
            c->setCancelTimeStep(timestep);
            cancelled.push(c);
        }
    }
}
void Center::MoveLateToRedy() {
    Car* c;
    for (int i = 0; i < 6; i++) {
        if (!late.dequeue(c)) break;
        c->setCarStatus(CarStatus::REDY);
        ready.enqueue(c);

    }
}
void Center::stepArrival(int timeStep) {
    GenerateCars(1000);
    DistributeFromIdle();
    MoveErlyToRedy();
    CancelFromLate(timeStep);
    MoveLateToRedy();
}

void Center::addToService(Car* c, int finishTime)
{
    InServ_cars.enqueue(c, -finishTime);
}

bool Center::peekServiceFinishTime(int& t)
{
    if (InServ_cars.isEmpty())
        return false;

    Car* c;
    int pri;
    InServ_cars.peek(c, pri);
    t = -pri;
    return true;
}

void Center::assignCarsToBays(int timestep)
{
    for (int i = 0; i < 6; i++)
    {
        int roll = rand() % 100 + 1;
        Car* c = nullptr;

        if (roll <= 60)
        {
            if (!WAIT_MU_list.isEmpty() && !Free_MU_List.isEmpty())
            {
                MechBay* b;
                Free_MU_List.peek(b);

                b->occupy();


                if (!b->isFree())
                    Free_MU_List.dequeue(b);

                WAIT_MU_list.dequeue(c);
                c->setBay(b);
            }
        }
        else if (roll <= 90)
        {
            if (!WAIT_EU_list.isEmpty() && !Free_EU_List.isEmpty())
            {
                ElecBay* b;
                Free_EU_List.peek(b);

                b->occupy();


                if (!b->isFree())
                    Free_EU_List.dequeue(b);

                WAIT_EU_list.dequeue(c);
                c->setBay(b);
            }
        }
        else
        {
            if (!WAIT_WU_list.isEmpty() && !Free_WU_List.isEmpty())
            {
                WashBay* b;
                Free_WU_List.peek(b);
                b->occupy();


                if (!b->isFree())
                    Free_WU_List.dequeue(b);

                WAIT_WU_list.dequeue(c);
                c->setBay(b);
            }
        }

        if (c != nullptr)
        {
            c->setCarStatus(CarStatus::SERV);
            addToService(c, timestep + SERVICE_TIME);
        }
    }
}

void Center::releaseFinishedCars(int timestep)
{
    int finish;
    while (peekServiceFinishTime(finish) && finish <= timestep)
    {
        Car* c;
        int pri;
        InServ_cars.dequeue(c, pri);

        Bay* b = c->getBay();
        if (b != nullptr)
        {
            b->addBusyTime(SERVICE_TIME);
            b->release();

            if (b->getRemainingCapacity() == 1)
            {
                switch (b->getType())
                {
                case BayType::MECH: Free_MU_List.enqueue(static_cast<MechBay*>(b)); break;
                case BayType::ELEC: Free_EU_List.enqueue(static_cast<ElecBay*>(b)); break;
                case BayType::WASH: Free_WU_List.enqueue(static_cast<WashBay*>(b)); break;
                default: break;
                }


            }

            c->setBay(nullptr);

        }

        int roll = rand() % 100 + 1;

        if (roll <= 40)
        {
            c->setCarStatus(CarStatus::FNSH);

            Finished_cars.push(c);
        }
        else
        {
            c->setCarStatus(CarStatus::WAIT);
            int r = rand() % 100 + 1;

            if (r <= 60)      WAIT_MU_list.enqueue(c);

            else if (r <= 90) WAIT_EU_list.enqueue(c);
            else              WAIT_WU_list.enqueue(c);
        }
    }
}