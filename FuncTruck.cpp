#include "Truck.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

float FuncTruck(truck* &t)
{
	if (t->enginepower != 0)
		return float(t->carryingcapacity) / t->enginepower;
	else {
		cout << "ERROR! Division by zero in func truck!" << endl;
		return 0;
	}
}