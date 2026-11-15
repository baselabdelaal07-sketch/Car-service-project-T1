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

	priQueue<Car*> DIAG_cars;                /////zeyad
	LinkedQueue<DiagBay*> Free_D_List;
	int totalCars = 0;
	void CreateBays(int nDiag, int nMech, int nElec, int nWash, int wbCap);



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

	void RandomSimulation();			////zeyad
	bool AllDone() const;




			
	const IDLE_LIST& GetIdle()      const { return idle; }
	const ERLY_LIST& GetErly()      const { return erly; }					////zeyad
	const LATE_LIST& GetLate()      const { return late; }
	const LinkedQueue<Car*>& GetReady()     const { return ready; }
	const WAIT_MU& GetWaitMU()    const { return WAIT_MU_list; }
	const WAIT_EU& GetWaitEU()    const { return WAIT_EU_list; }
	const WAIT_WU& GetWaitWU()    const { return WAIT_WU_list; }
	const priQueue<Car*>& GetInServ()    const { return InServ_cars; }
	const LinkedQueue<MechBay*>& GetFreeMU()    const { return Free_MU_List; }
	const LinkedQueue<ElecBay*>& GetFreeEU()    const { return Free_EU_List; }
	const LinkedQueue<WashBay*>& GetFreeWU()    const { return Free_WU_List; }
	const ArrayStack<Car*>& GetCancelled() const { return cancelled; }
	const ArrayStack<Car*>& GetFinished()  const { return Finished_cars; }
	const priQueue<Car*>& GetDiag()     const { return DIAG_cars; }
	const LinkedQueue<DiagBay*>& GetFreeDiag() const { return Free_D_List; }


};

