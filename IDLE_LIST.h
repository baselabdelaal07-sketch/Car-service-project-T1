#pragma once
#include"LinkedQueue.h"
#include"Car.h"
class IDLE_LIST: public LinkedQueue<Car*>
{
public:
	void insertCar(Car*newCar);
};

