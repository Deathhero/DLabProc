#include "Bus.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

float FuncBus(bus* &b)
{
	if (b->enginepower != 0)
		return float(b->passengercapacity * 75) / b->enginepower;
	else {
		cout << "ERROR! Division by zero in func bus!" << endl;
		return 0;
	}
}