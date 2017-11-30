#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Container.h"

using namespace std;

struct container* Init()
{
	struct container *lst;
	lst = new container;
	lst->cont = NULL;
	lst->next = NULL;
	lst->len = 0;
	lst->prev = NULL;
	return(lst);
}