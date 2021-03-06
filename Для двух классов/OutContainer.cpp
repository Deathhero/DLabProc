#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Container.h"

using namespace std;

void Out(car *a, ofstream &ofst);

void Out(container* &cont, ofstream &outFile)
{
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
		outFile << p->len << ": ";
		Out(p->cont, outFile);
		p = p->next;
	}
}