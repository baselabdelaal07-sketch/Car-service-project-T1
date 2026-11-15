#include "LATE_LIST.h"
bool LATE_LIST::CancelRandomCar(Car*& cancelled) {
    int n = GetCount();
    if (n < 1) return false;

    int randomCarIndex = rand() % n;
    LinkedQueue<Car*> temp;
    Car* c;
    for (int i = 0; i < n; i++) {
        dequeue(c);
        if (i == randomCarIndex)
            cancelled = c;
        else
            temp.enqueue(c);
    }
    while (temp.dequeue(c))
        enqueue(c);

    return true;
}