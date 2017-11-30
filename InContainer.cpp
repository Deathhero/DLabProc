#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Container.h"

using namespace std;

void CheckInputFile(ifstream &ifst);
void CheckWrongInput(ifstream &ifst);

car* In(ifstream &ifst);

int In(container* &cont, ifstream &ifst)
{
	CheckInputFile(ifst);
	if (ifst.eof()) 
	{
		cerr << "Empty File!" << endl;
		exit(1);
	}
	int len = 0;
	ifst >> len;
	CheckWrongInput(ifst);
	if (len < 0) 
	{
		cerr << "Incorrect len of container!" << endl;
		exit(1);
	}
	container *cur;
	cur = cont;
	for (int i = 0; i < len; i++)
	{
		car *c;
		if ((c = In(ifst)) != 0)
		{
			container *temp, *p;
			temp = new container;
			p = cur->next;
			cur->next = temp;
			temp->cont = c;
			temp->len = i + 1;
			temp->next = p;
			temp->prev = cur;
			if (p != NULL)
			{
				p->prev = temp;
			}
			cur = temp;
		}
	}
	cont = cur;
	return len;
}