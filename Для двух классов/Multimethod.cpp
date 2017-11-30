#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Container.h"

using namespace std;

void Out(car *a, ofstream &ofst);

void Multimethod(container* &c, ofstream &ofst)
{
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