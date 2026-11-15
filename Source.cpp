#include<iostream>
#include "Center.h"
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
	srand((unsigned int)time(0));  
	Center serviceCenter;
	serviceCenter.RandomSimulation();
	return 0;

}