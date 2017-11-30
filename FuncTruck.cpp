#include "Truck.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

float FuncTruck(truck* &t)
{
	if (t->enginepower != 0)
	{
		float k = float(t->carryingcapacity) /t->enginepower;
		if (abs((k / t->enginepower) - t->carryingcapacity) >= 0.00001) {
			cerr << "ERROR FUNC TRUCK OVERFLOW" << endl;
			return 0;
		}
		return k;
	}
	else {
		cout << "ERROR! Division by zero in func truck!" << endl;
		return 0;
	}
}