#include "Container.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "gtest/gtest.h"
#include "Test.h"
#include "Protect.h"

using namespace std;

struct container *Init();
void Clear(container* &cont);
int In(container* &cont, ifstream &inFile);
void Out(container* &cont, ofstream &outFile);
void Sort(container* &cont, int len);
void OutOnlyBus(container* &cont, ofstream &outFile);
void OutOnlyTruck(container* &cont, ofstream &outFile);
void OutOnlyPassengerCar(container* &cont, ofstream &outFile);

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "incorrect command line! Waited: command in_file out_file" << endl;
		exit(1);
	}

	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);

	cout << "Start" << endl;

	container *c;
	c = Init();

	int len = In(c, ifst);
	ofst << "Filled container. " << endl;
	Sort(c, len);
	Out(c, ofst);

	ifst.close();
	ofst.close();

	cout << "Stop" << endl;
	return 0;
	/*::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();*/
}
