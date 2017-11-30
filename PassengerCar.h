#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

struct passengercar {
	enum key { TRUCK, BUS, PASSENGERCAR };
	key k;
	int enginepower;
	float fuelconsumption;
	short int maxspeed;
};