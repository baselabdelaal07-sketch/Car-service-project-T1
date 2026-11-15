#pragma once
#include"priQueue.h"
#include"Car.h"

class ERLY_LIST:public priQueue<Car*>
{
	bool removeRandomCar(Car*&random);
};

