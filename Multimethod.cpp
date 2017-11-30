#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Container.h"

using namespace std;

void Out(car *a, ofstream &ofst);

void CheckOutputFile(ostream &ofst);

void Multimethod(container* &c, ofstream &ofst)
{
	CheckOutputFile(ofst);
	int len = c->len;
	if (c->len == 0)
	{
		return;
	}
	container *temp1;
	container *temp2;
	temp1 = c;
	for (int i = 0; i < len - 1; i++)
		temp1 = temp1->prev;
	while (temp1 != NULL)
	{
		temp2 = c;
		for (int i = 0; i < len - 1; i++)
			temp2 = temp2->prev;
		while (temp2 != NULL)
		{
			switch (temp1->cont->k)
			{
			case car::key::BUS:
			{
				switch (temp2->cont->k)
				{
				case car::key::BUS:
				{
					ofst << "Bus and Bus:" << endl;
					break;
				}
				case car::key::TRUCK:
				{
					ofst << "Bus and Truck:" << endl;
					break;
				}
				case car::key::PASSENGERCAR:
				{
					ofst << "Bus and Passenger Car:" << endl;
					break;
				}
				default:
					ofst << "Incorrect type of car!" << endl;
				}
				break;
			}
			case car::key::TRUCK:
			{
				switch (temp2->cont->k)
				{
				case car::key::BUS:
				{
					ofst << "Truck and Bus:" << endl;
					break;
				}
				case car::key::TRUCK:
				{
					ofst << "Truck and Truck:" << endl;
					break;
				}
				case car::key::PASSENGERCAR:
				{
					ofst << "Truck and Passenger Car:" << endl;
					break;
				}
				default:
					ofst << "Incorrect type of car!" << endl;
				}
				break;
			}
			case car::key::PASSENGERCAR:
			{
				switch (temp2->cont->k)
				{
				case car::key::BUS:
				{
					ofst << "Passenger Car and Bus:" << endl;
					break;
				}
				case car::key::TRUCK:
				{
					ofst << "Passenger Car and Truck:" << endl;
					break;
				}
				case car::key::PASSENGERCAR:
				{
					ofst << "Passenger Car and Passenger Car:" << endl;
					break;
				}
				default:
					ofst << "Incorrect type of car!" << endl;
				}
				break;
			}
			default:
				ofst << "Incorrect type of car!" << endl;
			}
			Out(temp1->cont, ofst);
			Out(temp2->cont, ofst);
			temp2 = temp2->next;
			ofst << endl;
		}
		temp1 = temp1->next; 
	}
}