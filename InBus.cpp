#include "Bus.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

void CheckInputFile(ifstream &ifst);
void CheckWrongInput(ifstream &ifst);

void InBus(bus* &b, ifstream &ifst)
{
	CheckInputFile(ifst);
	ifst >> b->enginepower >> b->fuelconsumption >> b->passengercapacity;
	CheckWrongInput(ifst);
	if (b->enginepower <= 0 || b->fuelconsumption <= 0 || b->passengercapacity <= 0)
	{
		cout << "Incorrect values in bus input." << endl;
		exit(1);
	}
}