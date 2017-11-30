#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Car.h"
#include "Truck.h"
#include "Bus.h"

using namespace std;

float FuncTruck(truck* &t);
float FuncBus(bus* &b);

float FuncCar(car* &c) {
	truck *t;
	bus *b;
	switch (c->k) {
	case car::key::BUS:
		b = (bus*)c;
		return FuncBus(b);
	case car::key::TRUCK:
		t = (truck*)c;
		return FuncTruck(t);
	default:
		return 0;
	}
}