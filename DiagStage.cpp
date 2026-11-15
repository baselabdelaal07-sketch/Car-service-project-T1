#include "DiagStage.h"
#include "DiagStage.h"
#include <cstdlib>

void DiagStage::AssignCarsToDiagnosis(int now,
    LinkedQueue<Car*>& REDY,
    LinkedQueue<Bay*>& Free_D,
    priQueue<Car*>& DIAG_Cars)
{
    // "if there is no car/bay to pick, move to the next part of the algorithm"
    while (!REDY.isEmpty() && !Free_D.isEmpty())
    {
        Car* c = nullptr;
        Bay* b = nullptr;
        REDY.dequeue(c);
        Free_D.dequeue(b);

        b->occupy();
        c->setBay(b);                         // the car points to its bay
        c->setCarStatus(CarStatus::DIAG);
        DIAG_Cars.enqueue(c, -(now + DIAG_STEPS));   // negative: earliest finish is served first
    }
}

void DiagStage::FinishDiagnosis(int now,
    priQueue<Car*>& DIAG_Cars,
    LinkedQueue<Bay*>& Free_D,
    WAIT_MU& waitMU,
    WAIT_EU& waitEU,
    WAIT_WU& waitWU,
    ArrayStack<Car*>& Cancelled_cars)
{
    Car* c = nullptr;
    int pri = 0;

    // The top of DIAG_Cars always has the earliest finish time, so stop at the first car not done.
    while (DIAG_Cars.peek(c, pri) && -pri <= now)
    {
        DIAG_Cars.dequeue(c, pri);

        // free the diagnosis bay and make it available again
        Bay* b = c->getBay();
        b->release();
        Free_D.enqueue(b);
        c->setBay(nullptr);

        if (rand() % 100 < P_CANCEL_AFTER)
        {
            c->setCarStatus(CarStatus::CNCL);
            c->setCT(now);                     // cancelled car: finish time = cancel time
            Cancelled_cars.push(c);
        }
        else
        {
            c->setCarStatus(CarStatus::WAIT);
            switch (rand() % 3)                // random WAIT list
            {
            case 0:  waitMU.enqueue(c); break;
            case 1:  waitEU.enqueue(c); break;
            default: waitWU.enqueue(c); break;
            }
        }
    }
}
