#pragma once
enum class BayType { DIAG, MECH, ELEC, WASH };  // lists of choices for the type of bay
class Bay
{
protected:         //notice that derived clasess - DiagBay, MechBay, ElecBay, WashBay - can access these variables
    int ID;         // Bay no 
    BayType type;   // Diag-Mech-Elec-Wash 
    int capacity;   // max cars inside at the same time
    int inUse;      // cars inside right now
    int busyTime;   // timesteps with at least one car // how many time steps the bay had a car in it 
public:
    Bay(int id, BayType t, int cap = 1);   
    virtual ~Bay() {}

    int getID() const;
    BayType getType() const;
    int getCapacity() const;
    int getInUse() const;
    int getRemainingCapacity() const; // returns capacity - inUse
    bool isFree() const;        // checks if it can accept at least one more car  
    bool isEmpty() const;       // no car inside __ ie checks if it is emty 

    bool occupy();              // one more car enters; false if the bay is full__ adds one more car__ increments cars in use
    bool release();             // one car leaves; false if the bay was already empty__ removes one more car __ decrements cars in use 

    void addBusyTime(int t);
    int getBusyTime() const;

    virtual char getPrefix() const = 0;   // 'D', 'M', 'E', 'W'__ pure virtual since the bay cant create one of it own , ie you cant create a plain Bay
    virtual void print() const;           // prints e.g. D4



};

std::ostream& operator<<(std::ostream& out, const Bay* b);          ///zeyad


class DiagBay : public Bay
{
public:
    DiagBay(int id);
    char getPrefix() const;
};

class MechBay : public Bay
{
public:
    MechBay(int id);
    char getPrefix() const;
};

class ElecBay : public Bay
{
public:
    ElecBay(int id);
    char getPrefix() const;
};
// WashBay is the only class whose capacity can not =1 
class WashBay : public Bay
{
public:
    WashBay(int id, int cap);   // cap = WB_Cap 
    char getPrefix() const;
    void print() const;         // prints ID and remaining capacity
};

