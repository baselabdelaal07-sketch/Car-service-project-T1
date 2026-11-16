#include<iostream>
#pragma once 
#include <cstdlib>
using namespace std;

#include "Car.h"

using namespace std;


#include "Bay.h"
#include "LinkedQueue.h"
#include "priQueue.h"
#include "ArrayStack.h"
#include "WAIT_MU.h"
#include "WAIT_EU.h"
#include "WAIT_WU.h"
#include "FreeWUBays.h"
#include "DiagStage.h"
////// Jana testing member 2 
// Counts a queue by emptying it into a temporary one and putting everything back.
template <typename T, typename Q>
int countQueue(Q& q)
{
    LinkedQueue<T> tmp;
    T x;
    int n = 0;
    while (q.dequeue(x)) { tmp.enqueue(x); n++; }
    while (tmp.dequeue(x)) q.enqueue(x);
    return n;
}

// Same idea for the priority queue.
int countPri(priQueue<Car*>& q)
{
    priQueue<Car*> tmp;
    Car* c = nullptr;
    int p = 0, n = 0;
    while (q.dequeue(c, p)) { tmp.enqueue(c, p); n++; }
    while (tmp.dequeue(c, p)) q.enqueue(c, p);
    return n;
}

int main()
{
    srand(42);   // fixed seed so every run gives the same result

    LinkedQueue<Car*> REDY;
    LinkedQueue<Bay*> Free_D;
    priQueue<Car*> DIAG_Cars;
    WAIT_MU waitMU;
    WAIT_EU waitEU;
    WAIT_WU waitWU;
    ArrayStack<Car*> Cancelled_cars;

    for (int i = 1; i <= 2; i++)
        Free_D.enqueue(new DiagBay(i));                          // 2 diagnosis bays

    int nextCar = 1;
    for (int now = 1; now <= 14; now++)
    {
        if (now <= 5)                                            // 2 new ready cars per step for 5 steps
            for (int k = 0; k < 2; k++, nextCar++)
                REDY.enqueue(new Car(nextCar, now, now, 3));     // Car(CID, PT, VT, DD)

        DiagStage::AssignCarsToDiagnosis(now, REDY, Free_D, DIAG_Cars);                                   // step 2.5
        DiagStage::FinishDiagnosis(now, DIAG_Cars, Free_D, waitMU, waitEU, waitWU, Cancelled_cars);       // step 2.7

        // count first: the lab LinkedQueue destructor prints text, so keep it out of the cout line
        int nRedy = countQueue<Car*>(REDY);
        int nFree = countQueue<Bay*>(Free_D);
        int nDiag = countPri(DIAG_Cars);
        int nMU = countQueue<Car*>(waitMU);
        int nEU = countQueue<Car*>(waitEU);
        int nWU = countQueue<Car*>(waitWU);
        cout << "t=" << now << "  REDY=" << nRedy << "  FreeD=" << nFree
            << "  DIAG=" << nDiag << "  MU=" << nMU << "  EU=" << nEU
            << "  WU=" << nWU << "\n";
    }
    return 0;
}
   
