#include "Bus.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

void OutBus(bus* &b, ofstream &ofst) {
	ofst << "It is bus." << endl;
	ofst << "Engine power = " << b->enginepower << ". Passenger capacity =  " << b->passengercapacity << endl;
	ofst << "Fuel consumption = " << b->fuelconsumption << endl;
}