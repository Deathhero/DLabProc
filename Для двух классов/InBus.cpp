#include "Bus.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

void InBus(bus* &b, ifstream &ifst)
{
	ifst >> b->enginepower;
	ifst >> b->passengercapacity;
}