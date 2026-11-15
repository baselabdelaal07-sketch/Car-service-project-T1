#include "UI.h"
#include "Center.h"
#include <iostream>
#include <conio.h>     
using namespace std;

void UI::PrintAll(int timestep, const Center& center) const
{
	const int IDLE_LIMIT = 15;    /////zeyad

	cout << "Current Timestep:" << timestep << endl;

	// ---------------- IDLE ----------------
	cout << "\n================ IDLE Cars [CarID, VT, PT] ================\n";
	cout << center.GetIdle().GetCount() << " cars: ";
	center.GetIdle().print(IDLE_LIMIT);
	cout << endl;

	// ---------------- ERLY, LATE, REDY ----------------
	cout << "\n================ ERLY & LATE & REDY Cars [CarID, VT, PT] ================\n";
	cout << center.GetErly().GetCount() << " ERLY: ";
	center.GetErly().print();
	cout << endl;

	cout << center.GetLate().GetCount() << " LATE: ";
	center.GetLate().print();
	cout << endl;

	cout << center.GetReady().GetCount() << " REDY: ";
	center.GetReady().print();
	cout << endl;

	// ---------------- Free diagnosis bays ----------------
	cout << "\n================ Free Diagnosis Bays IDs ================\n";
	cout << center.GetFreeDiag().GetCount() << " Diag Bays: ";
	center.GetFreeDiag().print();
	cout << endl;

	// ---------------- DIAG ----------------
	cout << "\n================ DIAG Cars [CarID, Diag Bay ID] ================\n";
	cout << center.GetDiag().GetCount() << " Cars in Diag: ";
	center.GetDiag().print();
	cout << endl;

	// ---------------- Cars waiting for service ----------------
	cout << "\n================ Cars waiting for Service [CarID, next Serv Time] ================\n";
	cout << center.GetWaitMU().GetCount() << " MB cars waiting: ";
	center.GetWaitMU().print();
	cout << endl;

	cout << center.GetWaitEU().GetCount() << " EB cars waiting: ";
	center.GetWaitEU().print();
	cout << endl;

	cout << center.GetWaitWU().GetCount() << " WB cars waiting: ";
	center.GetWaitWU().print();
	cout << endl;

	// ---------------- Free service bays ----------------
	cout << "\n================ Free Bays IDs ================\n";
	cout << center.GetFreeMU().GetCount() << " MB free: ";
	center.GetFreeMU().print();
	cout << endl;

	cout << center.GetFreeEU().GetCount() << " EB free: ";
	center.GetFreeEU().print();
	cout << endl;

	cout << center.GetFreeWU().GetCount() << " WB free: ";
	center.GetFreeWU().print();
	cout << endl;

	// ---------------- In-service cars ----------------
	cout << "\n================ In-Service Cars [CarID, Bay ID] ================\n";
	cout << center.GetInServ().GetCount() << " Cars in Serv: ";
	center.GetInServ().print();
	cout << endl;

	// ---------------- Cancelled cars (stack: latest cancel time first) ----------------
	cout << "\n================ CNCL Cars [CarID, CancelTime] ================\n";
	cout << center.GetCancelled().GetCount() << " cancelled: ";
	center.GetCancelled().print();
	cout << endl;

	// ---------------- Finished cars (stack: latest finish time first) ----------------
	cout << "\n================ FNSH Cars [CarID, FinishTime] ================\n";
	cout << center.GetFinished().GetCount() << " DONE: ";
	center.GetFinished().print();
	cout << endl;
}

void UI::WaitForNextStep() const
{
	cout << "PRESS ANY KEY TO MOVE TO NEXT STEP !" << endl;
	_getch();
}
