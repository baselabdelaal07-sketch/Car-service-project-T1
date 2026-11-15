#include "Bay.h"
#include <iostream>
Bay::Bay(int id, BayType t, int cap)
{
    ID = id;
    type = t;
    capacity = cap;
    inUse = 0;
    busyTime = 0;
}

int Bay::getID() const { return ID; }
BayType Bay::getType() const { return type; }
int Bay::getCapacity() const { return capacity; }
int Bay::getInUse() const { return inUse; }
int Bay::getRemainingCapacity() const { return capacity - inUse; }
bool Bay::isFree() const { return inUse < capacity; }
bool Bay::isEmpty() const { return inUse == 0; }

bool Bay::occupy()
{
    if (!isFree())
        return false;
    inUse++;
    return true;
}

bool Bay::release()
{
    if (inUse == 0)
        return false;
    inUse--;
    return true;
}

void Bay::addBusyTime(int t) { busyTime += t; }
int Bay::getBusyTime() const { return busyTime; }

void Bay::print() const
{
    std::cout << getPrefix() << ID;
}

DiagBay::DiagBay(int id) : Bay(id, BayType::DIAG, 1) {}
char DiagBay::getPrefix() const { return 'D'; }

MechBay::MechBay(int id) : Bay(id, BayType::MECH, 1) {}
char MechBay::getPrefix() const { return 'M'; }

ElecBay::ElecBay(int id) : Bay(id, BayType::ELEC, 1) {}
char ElecBay::getPrefix() const { return 'E'; }

WashBay::WashBay(int id, int cap) : Bay(id, BayType::WASH, cap) {}
char WashBay::getPrefix() const { return 'W'; }

void WashBay::print() const
{
    std::cout << getPrefix() << ID << "(" << getRemainingCapacity() << " left)";
}


std::ostream& operator<<(std::ostream& out, const Bay* b)
{
    b->print();
    return out;
}                       ////zeyad