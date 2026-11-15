#pragma once
#include"Car.h"
#include"LinkedList.h"
class LATE_LIST:public LinkedList<Car*>
{
public:
	void CancelRandomCar();
};

