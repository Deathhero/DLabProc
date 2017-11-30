#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Car.h"
#include "Truck.h"
#include "Bus.h"

using namespace std;

void InTruck(truck* &t, ifstream &ifst);
void InBus(bus* &b, ifstream &ifst);

car* In(ifstream &ifst) {
	car *c;
	truck *t;
	bus *b;
	int k1;
	ifst >> k1;
	switch (k1) {
	case 1:
		t = new truck;
		t->k = truck::key::TRUCK;
		InTruck(t, ifst);
		return (car*)t;
	case 2:
		b = new bus;
		b->k = bus::key::BUS;
		InBus(b, ifst);
		return (car*)b;
	default:
		return 0;
	}
}