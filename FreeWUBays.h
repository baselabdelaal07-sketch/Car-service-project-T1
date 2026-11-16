#pragma once
//  a wash bay stays in this queue as long as it still has room. It is removed only when it
// becomes full, and it re-joins at the back when a car leaves a full bay.

#include "Car.h"
#include "Bay.h"
#include "LinkedQueue.h"

class FreeWUBays : public LinkedQueue<Bay*>
{
public:
    // Puts the car into the bay at the front of the list and returns that bay.
    // Returns nullptr if no wash bay has room (the car must keep waiting).   O(1)
    Bay* AllocateCar(Car* c)
    {
        Bay* b = nullptr;
        if (!peek(b))
            return nullptr;

        b->occupy();
        c->setBay(b);                  // the car points to its bay, nothing is copied
        if (!b->isFree())              // bay is full now, so it is no longer "free"
            dequeue(b);
        return b;
    }

    // The car leaves its wash bay.                                            O(1)
    void ReleaseCar(Car* c)
    {
        Bay* b = c->getBay();
        if (b == nullptr)
            return;

        bool wasFull = !b->isFree();
        b->release();
        c->setBay(nullptr);
        if (wasFull)                   // it has room again, so it re-joins the free list
            enqueue(b);
    }
};