#include "Car.h"
Car::Car() {

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
void Car::setTW(int tw){
	TW += tw;
}
void Car::setTS(int ts){

}
void Car::setFT(int ft){

}
void Car::setCT(int ct){

}
void Car::setBay(Bay*b){

}
void Car::print() {
	cout << '[ ' << CID << ',' << VT << ',' << PT<<' ]' << endl;
}
ostream& operator<<(ostream& out, Car* c) {
	c->print();      
	return out;     
}