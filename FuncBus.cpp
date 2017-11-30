#include "Bus.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

float FuncBus(bus* &b)
{
	if (b->enginepower != 0)
	{
		float k = float(b->passengercapacity * 75) / b->enginepower;
		if (abs((k / b->enginepower) - (b->passengercapacity * 75)) >= 0.00001) {
			cerr << "ERROR FUNC BUS OVERFLOW" << endl;
			return 0;
		}
		return k;
	}
	else {
		cout << "ERROR! Division by zero in func bus!" << endl;
		return 0;
	}
}