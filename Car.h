#pragma once
#include"Bay.h"
#include<iostream>
using namespace std;
enum class CarStatus {
	IDLE,ERLY,LATE,REDY,DIAG,WAIT,SERV,CNCL,FNSH
};
enum class SeqType {
	NoSeqSet,SS,FS
};
class Car {
private:
	int	CID;
	int PT;//appointment time
	int VT;//arrival time 
	int DD;
	int TW, TS, FT, CT;// total wait, total service time, finsih time, cancel time
	int nextServTime;		///zeyad

	
	CarStatus status;
	SeqType ST;//ST is a variable for the sequence type for the car
	Bay* bay;

public:
	Car(int id, int vt, int pt, int dd);
	int getCID();
	int getPT();
	int getVT();
	int getDD();
	int getTW();
	int getTS();
	int getFT();
	int getCT();
	Bay* getBay();
	CarStatus getCarStatus();
	SeqType getSeqType();
	void setCarStatus(CarStatus cs);
	void setSeqType(SeqType seqtype);
	void setTotalWaitTime (int tw);
	void setTotalServiceTime(int ts);
	void setFinishTimeStep(int ft);
	void setCancelTimeStep(int ct);
	void setBay(Bay*b);
	void print();


	int getNextServTime();
	void setNextServTime(int t);			////zeyad

};
ostream& operator<<(ostream& out, Car* c);