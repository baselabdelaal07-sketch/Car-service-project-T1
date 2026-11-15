#pragma once
#include"IDLE_LIST.h"
#include"ERLY_LIST.h"
#include"LATE_LIST.h"
#include"LinkedQueue.h"
#include"Car.h"
#include"ArrayStack.h"
class Center
{
private:
	IDLE_LIST idle;
	ERLY_LIST erly;
	LATE_LIST late;
	LinkedQueue<Car*> ready;
	ArrayStack<Car*> cancelled;
	

public:
	void GenerateCars(int n);
	void DistributeFromIdle();
	void MoveErlyToRedy();
	void CancelFromLate(int timeStep);
	void MoveLateToRedy(); 
	void stepArrival(int timeStep);
};

