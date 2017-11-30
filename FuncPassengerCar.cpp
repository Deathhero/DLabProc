#include "PassengerCar.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

float FuncPassengerCar(passengercar* &p)
{
	if (p->enginepower != 0)
		return float(p->maxspeed) / p->enginepower;
	else {
		cout << "ERROR! Division by zero in func passenger car!" << endl;
		return 0;
	}
}