#pragma once
#include "LinkedQueue.h"
#include"Car"

class WAIT_EU : public LinkedQueue<Car*>
{
    int totalTime;
public:
    WAIT_EU();
    bool enqueue(Car* c);       // adds the car's MU time to totalTime
    bool dequeue(Car*& c);      // subtracts it again
    int  GetTotalServiceTime() const;
};