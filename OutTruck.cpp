#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Truck.h"

using namespace std;

void CheckOutputFile(ostream &ofst);

void OutTruck(truck* &t, ofstream &ofst) 
{
	CheckOutputFile(ofst);
	ofst << "It is truck." << endl;
	ofst << "Engine power = " << t->enginepower << ". Carrying capacity =  " << t->carryingcapacity << endl;
	ofst << "Fuel consumption = " << t->fuelconsumption << endl;
}