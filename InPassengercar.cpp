#include "Passengercar.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

void CheckInputFile(ifstream &ifst);
void CheckWrongInput(ifstream &ifst);

void InPassengercar(passengercar* &p, ifstream &ifst)
{
	CheckInputFile(ifst);
	ifst >> p->enginepower >> p->fuelconsumption >> p->maxspeed;
	CheckWrongInput(ifst);
	if (p->enginepower <= 0 || p->fuelconsumption <= 0 || p->maxspeed <= 0)
	{
		cout << "Incorrect values in passenger car input." << endl;
		exit(1);
	}

}