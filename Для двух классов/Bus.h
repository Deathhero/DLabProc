#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

struct bus {
	enum key { TRUCK, BUS };
	key k;
	int enginepower;
	short int passengercapacity; // перелетные или нет
};

//void InBus(bus* &b, ifstream &ifst);
//void OutBus(bus* &b, ofstream &ofst);