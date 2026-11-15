#include "Car.h"
Car::Car(int id,int vt, int pt, int dd) {
	CID = id;
	VT = vt;
	PT = pt;
	DD = dd;
	bay = nullptr;
	CT = -1; //no cancel time or finish time at start
	TW = 0;
	TS = 0;
	ST = SeqType::NoSeqSet;
	FT = -1;
	status = CarStatus::IDLE;
}
int Car::getCID() {
	return CID;
}
int Car::getPT() {
	return PT;
}
int Car::getVT(){
	return VT;
}
int Car::getDD(){
	return DD;
}
int Car::getTW(){
	return TW;
}
int Car::getTS(){
	return TS;
}
int Car::getFT(){
	return FT;
}
int Car::getCT(){
	return CT;
}
Bay* Car::getBay(){
	return bay;
}
CarStatus Car::getCarStatus(){
	return status;
}
SeqType Car::getSeqType(){
	return ST;
}
void Car::setCarStatus(CarStatus cs){
	status = cs;
}
void Car::setSeqType(SeqType st){
	ST = st;
}
void Car::setTotalWaitTime(int tw){
	TW += tw;
}
void Car::setTotalServiceTime(int ts){

}
void Car::setFinishTimeStep(int ft){
	FT = ft;
}
void Car::setCancelTimeStep(int ct){
	CT = ct;
}
void Car::setBay(Bay*b){
	bay = b;
}
void Car::print() {
	cout << '[ ' << CID << ',' << VT << ',' << PT<<' ]' << endl;
}
ostream& operator<<(ostream& out, Car* c) {
	c->print();      
	return out;     
}