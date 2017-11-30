#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

struct car 
{
	enum key { TRUCK, BUS, PASSENGERCAR };
	key k; // ключ
		   // используемые альтернативы
};