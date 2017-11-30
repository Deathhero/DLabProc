#include "Bus.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

float FuncBus(bus* &b)
{
	return float(b->passengercapacity) * 75 / b->enginepower;
}