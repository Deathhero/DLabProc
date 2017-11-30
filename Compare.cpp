#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Car.h"

using namespace std;

float FuncCar(car* &c);

bool Compare(car *c1, car *c2)
{
	return (FuncCar(c1)>FuncCar(c2));
}