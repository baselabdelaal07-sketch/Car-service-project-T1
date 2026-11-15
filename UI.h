#ifndef UI_H
#define UI_H

 
#include "Center.h"

class UI
{
public:
	void PrintAll(int timestep, const Center& center)const;
	void WaitForNextStep() const;
};



#endif
