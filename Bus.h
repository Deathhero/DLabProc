#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

struct bus 
{
	enum key { TRUCK, BUS, PASSENGERCAR };
	key k;
	int enginepower;
	short int passengercapacity;
	float fuelconsumption;
};