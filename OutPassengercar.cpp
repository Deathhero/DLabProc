#include "Passengercar.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

void OutPassengercar(passengercar* &p, ofstream &ofst) {
	ofst << "It is passengercar." << endl;
	ofst << "Engine power = " << p->enginepower << ". Max speed =  " << p->maxspeed << endl;
}