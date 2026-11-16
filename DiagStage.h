#pragma once
#include "Car.h"
#include "Bay.h"
#include "LinkedQueue.h"
#include "priQueue.h"
#include "ArrayStack.h"
#include "WAIT_MU.h"
#include "WAIT_EU.h"
#include "WAIT_WU.h"
class DiagStage
{
    
    public:
        enum {
            DIAG_STEPS = 3,        //step 2.6, diagnosis takes 3 timesteps
            P_CANCEL_AFTER = 20 }; //step 2.7,20% chance to cancel after diagnosis  // only setting values for these names 

        // Step 2.5: for every free diagnosis bay, take one car from REDY.
        // DIAG_Cars is ordered by finish time -> priqueue
        // priority first, so the priority is stored as -(finish time): earliest finish = highest.

        static void AssignCarsToDiagnosis(int now,
            LinkedQueue<Car*>&REDY,   // cars waiting for diagnosis
            LinkedQueue<Bay*>&Free_D, // free diagnosis bays
            priQueue<Car*>&DIAG_Cars); // cars currently in diagnosis, ordered by finish time

        // now=current timestep number, needed time to finish diagnosis is (now +3),

        // Step 2.7: every car that finished its 3 timesteps leaves DIAG.
        // 20% go to the cancelled list, the rest go to a random WAIT list.
        // The diagnosis bay is released and returned to Free_D.
        static void FinishDiagnosis(int now,
            priQueue<Car*>&DIAG_Cars, // cars currently in diagnosis, ordered by finish tim
            LinkedQueue<Bay*>&Free_D, // free diagnosis bays
            WAIT_MU & waitMU,  // waiting list for mechanical repair
            WAIT_EU & waitEU, 
            WAIT_WU & waitWU,
            ArrayStack<Car*>&Cancelled_cars); // cars that cancelled after diagnosis
    };


