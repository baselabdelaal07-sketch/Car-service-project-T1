#pragma once
#include "LinkedQueue.h"
#include"Car.h"

class WAIT_EU : public LinkedQueue<Car*>
{
    int totalTime;
    int serviceTime = 4;   //  fixed for now in step 2.9 in phase 1.2
public:
    WAIT_EU() {
        totalTime = 0;
    }
    bool enqueue(Car* c)
    {

        LinkedQueue<Car*>::enqueue(c);   // asks the inherited linked queue part to add the car 

        
            totalTime += serviceTime;
           

        return true;                                
    }
   
    bool dequeue(Car*& c) {
        if (isEmpty())
            return false;

        LinkedQueue<Car*>::dequeue(c);   
        totalTime -= serviceTime;
        return true;
    }
    int  GetTotalServiceTime() const
    {
        return totalTime;
    }
};