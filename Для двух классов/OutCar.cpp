#include <iostream>
#include "Car.h"
#include "Truck.h"
#include "Bus.h"

using namespace std;

void OutBus(bus* &b, ofstream &ofst);
void OutTruck(truck* &t, ofstream &ofst);

void Out(car *c, ofstream &ofst) {
	truck *t;
	bus *b;
	switch (c->k) {
	case car::key::TRUCK:
		t = (truck*)c;
		OutTruck(t, ofst);
		break;
	case car::key::BUS:
		b = (bus*)c;
		OutBus(b, ofst);
		break;
	default:
		ofst << "Incorrect car!" << endl;
	}
}