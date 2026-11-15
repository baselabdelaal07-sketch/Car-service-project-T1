#pragma once
#include "priQueue.h"
#include "Car.h"

class InServ_cars : public priQueue<Car*>
{
public:
	bool enqueue(Car* c, int finishTime);

	bool dequeue(Car*& c, int &finishTime);

bool peekFinishTime(int& t);
};

