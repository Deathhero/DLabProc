#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Car.h"

using namespace std;

// Простейший контейнер на основе двунаправленного линейного списка
struct container
{
	car *cont;
	int len;
	struct container *next;
	struct container *prev;
};