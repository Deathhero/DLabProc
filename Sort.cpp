#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Container.h"

using namespace std;

bool Compare(car *c1, car *c2);

void Sort(container* &cont, int len)
{
	container *p;
	p = cont;
	bool flag;
	do
	{
		flag = false;
		for (int i = 0; i < len - 1; i++)
		{
			p = p->prev;
		}
		while (p->next != NULL)
		{
			car *one;
			one = p->cont;
			p = p->next;
			car *two;
			two = p->cont;
			bool k = Compare(one, two);
			if (k == true)
			{
				p->cont = one;
				p = p->prev;
				p->cont = two;
				flag = true;
			}
			else
			{
				p = p->prev;
			}
			p = p->next; // ïåðåõîä ê ñëåäóþùåìó óçëó
		}
	} while (flag);
}