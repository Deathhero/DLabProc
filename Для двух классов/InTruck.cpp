#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Truck.h"

using namespace std;

void InTruck(truck* &t, ifstream &ifst) {
	ifst >> t->enginepower;
	ifst >> t->carryingcapacity;
}