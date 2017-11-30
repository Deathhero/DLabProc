#include "Passengercar.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

void InPassengercar(passengercar* &p, ifstream &ifst)
{
	ifst >> p->enginepower;
	ifst >> p->maxspeed;
}