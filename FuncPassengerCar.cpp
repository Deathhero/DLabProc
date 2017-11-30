#include "PassengerCar.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

float FuncPassengerCar(passengercar* &p)
{
	return float(p->maxspeed) / p->enginepower;
}