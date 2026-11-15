#pragma once
#include"IDLE_LIST.h"
#include"ERLY_LIST.h"
#include"LATE_LIST.h"
#include"LinkedQueue.h"
#include"Car.h"
#include"ArrayStack.h"
#include "Bay.h"
#include "WAIT_MU.h"
#include "WAIT_EU.h"
#include "WAIT_WU.h"
class Center
{
private:
	IDLE_LIST idle;
	ERLY_LIST erly;
	LATE_LIST late;
	LinkedQueue<Car*> ready;
	ArrayStack<Car*> cancelled;
	static const int SERVICE_TIME = 4;

	WAIT_MU WAIT_MU_list;
	WAIT_EU WAIT_EU_list;


	WAIT_WU WAIT_WU_list;

	priQueue<Car*> InServ_cars;

	LinkedQueue<MechBay*> Free_MU_List;

	LinkedQueue<ElecBay*> Free_EU_List;
	LinkedQueue<WashBay*> Free_WU_List;

	ArrayStack<Car*> Finished_cars;

	void addToService(Car* c, int finishTime);

	bool peekServiceFinishTime(int& t);

	

public:
	void GenerateCars(int n);
	void DistributeFromIdle();
	void MoveErlyToRedy();
	void CancelFromLate(int timeStep);
	void MoveLateToRedy(); 
	void stepArrival(int timeStep);
	void assignCarsToBays(int timestep);
	void releaseFinishedCars(int timestep);
};

