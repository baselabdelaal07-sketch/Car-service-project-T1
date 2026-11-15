#include "InServ_cars.h"
#include"Car.h"
#include<iostream>
bool InServ_cars::enqueue(Car* c, int finishTime)
{
    priQueue<Car*>::enqueue(c, -finishTime);   
    return true;                               
}

bool InServ_cars::dequeue(Car*& c, int& finishTime)
{
    if (isEmpty())                              
        return false;

    int pri;
    priQueue<Car*>::dequeue(c, pri);             
    finishTime = -pri;                           
    return true;
}

bool InServ_cars::peekFinishTime(int& t)
{
    if (isEmpty())                      
        return false;

    Car* c;                              
    int pri;                             
    priQueue<Car*>::peek(c, pri);        
    t = -pri;                           
    return true;
}