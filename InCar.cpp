#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Car.h"
#include "Truck.h"
#include "Bus.h"
#include "PassengerCar.h"

using namespace std;

void InTruck(truck* &t, ifstream &ifst);
void InBus(bus* &b, ifstream &ifst);
void InPassengercar(passengercar* &p, ifstream &ifst);

void CheckInputFile(ifstream &ifst);
void CheckWrongInput(ifstream &ifst);

car* In(ifstream &ifst) 
{
	CheckInputFile(ifst);
	car *c;
	truck *t;
	bus *b;
	passengercar *p;
	int k1;
	ifst >> k1;
	CheckWrongInput(ifst);
	if (!(1 <= k1 && k1 <= 3)) 
	{
		cerr << "Error: unknown type" << endl;
		exit(1);
	}
	if (ifst.eof()) 
	{
		cerr << "Error: no data after type!" << endl;
		exit(1);
	}
	switch (k1) 
	{
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
	case 3:
		p = new passengercar;
		p->k = passengercar::key::PASSENGERCAR;
		InPassengercar(p, ifst);
		return (car*)p;
	default:
		cerr << "Incorrect car!" << endl;
		return 0;
	}
}