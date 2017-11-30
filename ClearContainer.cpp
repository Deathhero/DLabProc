#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Container.h"

using namespace std;

void Clear(container* &cont)
{
	while (cont->cont != NULL)
	{
		container *temp;
		temp = cont->prev;
		temp->next = NULL;
		delete cont;
		cont = temp;
	}
}