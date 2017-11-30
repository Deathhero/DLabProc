#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Container.h"

using namespace std;

void Out(car *a, ofstream &ofst);
float FuncCar(car* &c);

void CheckOutputFile(ostream &ofst);

void OutOnlyPassengerCar(container* &cont, ofstream &outFile)
{
	CheckOutputFile(outFile);
	int len = cont->len;
	outFile << "Container contains " << len << " elements." << endl;
	if (cont->len == 0)
	{
		return;
	}
	container *p;
	p = cont;
	for (int i = 0; i < len - 1; i++)
	{
		p = p->prev;
	}
	while (p != NULL)
	{
		if (p->cont->k == car::key::PASSENGERCAR) {
			outFile << p->len << ": ";
			Out(p->cont, outFile);
			outFile << "Ñargo weight / Engine power = " << FuncCar(p->cont) << endl;
		}
		p = p->next;
	}
}