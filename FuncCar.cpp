#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Car.h"
#include "PassengerCar.h"
#include "Truck.h"
#include "Bus.h"

using namespace std;

float FuncTruck(truck* &t);
float FuncBus(bus* &b);
float FuncPassengerCar(passengercar* &p);

float FuncCar(car* &c) {
	truck *t;
	passengercar *p;
	bus *b;
	switch (c->k) {
	case car::key::BUS:
		b = (bus*)c;
		return FuncBus(b);
	case car::key::TRUCK:
		t = (truck*)c;
		return FuncTruck(t);
	case car::key::PASSENGERCAR:
		p = (passengercar*)c;
		return FuncPassengerCar(p);
	default:
		return 0;
	}
}