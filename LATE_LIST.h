#pragma once
#include"Car.h"
#include"LinkedQueue.h"
class LATE_LIST:public LinkedQueue<Car*>
{
public:
	bool CancelRandomCar(Car*& cancelled);
};

