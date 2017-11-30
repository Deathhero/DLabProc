#include <iostream>
#include "Car.h"
#include "Truck.h"
#include "Bus.h"
#include "PassengerCar.h"

using namespace std;

void OutBus(bus* &b, ofstream &ofst);
void OutTruck(truck* &t, ofstream &ofst);
void OutPassengercar(passengercar* &p, ofstream &ofst);

void CheckOutputFile(ostream &ofst);

void Out(car *c, ofstream &ofst) 
{
	CheckOutputFile(ofst);
	truck *t;
	bus *b;
	passengercar *p;
	switch (c->k) 
	{
	case car::key::TRUCK:
		t = (truck*)c;
		OutTruck(t, ofst);
		break;
	case car::key::BUS:
		b = (bus*)c;
		OutBus(b, ofst);
		break;
	case passengercar::key::PASSENGERCAR:
		p = (passengercar*)c;
		OutPassengercar(p, ofst);
		break;
	default:
		ofst << "Incorrect car!" << endl;
	}
}