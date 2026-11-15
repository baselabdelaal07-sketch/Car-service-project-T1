#include "IDLE_LIST.h"
   void IDLE_LIST::insertCar(Car * newCar) {
       // newCar heya ay car da5la el idle men list tanya 
        LinkedQueue<Car*> temp;
        Car* c;
        bool inserted = false;

        while (dequeue(c)) {
            if (!inserted && c->getVT() > newCar->getVT()) {
                temp.enqueue(newCar);     
                inserted = true;
            }
            temp.enqueue(c);
        }
        if (!inserted)
            temp.enqueue(newCar);       

        while (temp.dequeue(c))
            enqueue(c);                  
    }