#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

struct truck 
{
	enum key { TRUCK, BUS, PASSENGERCAR };
	key k;
	int enginepower;
	int carryingcapacity;
	float fuelconsumption;
};