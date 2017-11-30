#include "Truck.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

float FuncTruck(truck* &t)
{
	return float(t->carryingcapacity) / t->enginepower;
}