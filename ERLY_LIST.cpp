#include "ERLY_LIST.h"
bool ERLY_LIST :: removeRandomCar(Car*& random) {
    int n = GetCount();
    if (n < 1) return false;

    int randomCarIndex = rand() % n;
    priQueue<Car*> temp;
    Car* c;
    int pri;
    for (int i = 0; i < n; i++) {
        dequeue(c,pri);
        if (i == randomCarIndex)
            random = c;
        else
            temp.enqueue(c,pri);
    }

    while (temp.dequeue(c,pri))
        enqueue(c,pri);

    return true;
}