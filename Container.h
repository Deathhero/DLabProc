#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Car.h"

using namespace std;

// ���������� ��������� �� ������ ���������������� ��������� ������
struct container
{
	car *cont;
	int len;
	struct container *next;
	struct container *prev;
};