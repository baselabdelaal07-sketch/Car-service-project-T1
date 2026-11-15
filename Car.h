#pragma once
#include"Bay.h"
#include<iostream>
using namespace std;
enum class CarStatus {
	IDLE,ERLY,LATE,REDY,DIAG,WAIT,SERV,CNCL,FNSH
};
enum class SeqType {
	SS,FS
};
class Car {
private:
	int	CID;
	int PT;//appointment time
	int VT;//arrival time 
	int DD;
	int TW, TS, FT, CT;// total wait, total service time, finsih time, cancel time
	CarStatus status;
	SeqType ST;//ST is a variable for the sequence type for the car
	Bay* bay;

public:
	Car();
	int getCID();
	int getPT();
	int getVT();
	int getDD();
	int getTW();
	int getTS();
	int getFT();
	int getCT();
	int getDD();
	Bay* getBay();
	CarStatus getCarStatus();
	SeqType getSeqType();
	void setCarStatus(CarStatus cs);
	void setSeqType(SeqType seqtype);
	void setTW(int tw);
	void setTS(int ts);
	void setFT(int ft);
	void setCT(int ct);
	void setBay(Bay*b);
	void print();

};
ostream& operator<<(ostream& out, Car* c);