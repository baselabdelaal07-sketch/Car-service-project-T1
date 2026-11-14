#pragma once
#include "LinkedQueue.h"
#include"Car.h"

class WAIT_EU : public LinkedQueue<Car*>
{
    int totalTime;
public:
    WAIT_EU() {
        totalTime = 0;
    }
    bool enqueue(Car* c)
    {
        bool ok = LinkedQueue<Car*>::enqueue(c);   // asks the inherited linked queue part to add the car and if yes or no it will be returned in ok

        if (ok)                                    
            totalTime += c->GetEUTime();           ///GetEUTime() to get the service time of each car will be implemented later on in phase 2

        return ok;                                
    }
   
    bool dequeue(Car*& c) {
        bool ok = LinkedQueue<Car*>::dequeue(c);
        if (ok)
            totalTime -= c->GetEUTime();

        return ok;
    }
    int  GetTotalServiceTime() const
    {
        return totalTime;
    }
};