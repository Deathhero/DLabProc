#include "Passengercar.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

void OutPassengercar(passengercar* &p, ofstream &ofst) {
	ofst << "It is passenger car." << endl;
	ofst << "Engine power = " << p->enginepower << ". Max speed =  " << p->maxspeed << endl;
	ofst << "Fuel consumption = " << p->fuelconsumption << endl;
}