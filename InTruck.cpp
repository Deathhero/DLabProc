#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Truck.h"

using namespace std;

void CheckInputFile(ifstream &ifst);
void CheckWrongInput(ifstream &ifst);

void InTruck(truck* &t, ifstream &ifst) {
	CheckInputFile(ifst);
	ifst >> t->enginepower >> t->fuelconsumption >> t->carryingcapacity;
	CheckWrongInput(ifst);
	if (t->enginepower <= 0 || t->fuelconsumption <= 0 || t->carryingcapacity <= 0)
	{
		cout << "Incorrect values in truck input." << endl;
		exit(1);
	}
}