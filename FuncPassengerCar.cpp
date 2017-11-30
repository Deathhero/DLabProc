#include "PassengerCar.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

float FuncPassengerCar(passengercar* &p)
{
	if (p->enginepower != 0)
	{
		float k = float(p->maxspeed) / p->enginepower;
		if (abs((k / p->enginepower) - p->maxspeed) >= 0.00001) 
		{
			cerr << "ERROR FUNC PASSENGER CAR OVERFLOW" << endl;
			return 0;
		}
		return k;
	}
	else 
	{
		cout << "ERROR! Division by zero in func passenger car!" << endl;
		return 0;
	}
}