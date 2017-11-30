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
void Out(container* &cont, ostream &outFile);
void Sort(container* &cont, int len, int d);
void OutOnlyBus(container* &cont, ostream &outFile);
void OutOnlyTruck(container* &cont, ostream &outFile);
void OutOnlyPassengerCar(container* &cont, ostream &outFile);
void Multimethod(container* &c, ostream &ofst);

int main(int argc, char* argv[]) 
{
	if (argc != 3) 
	{
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

	int k1 = 10;
	int k = 10;
	while (k != 0) {
		
		cout << "Input number:" << endl;
		cout << "1 - Out container" << endl;
		cout << "2 - Sort and out container" << endl;
		cout << "3 - Out only bus" << endl;
		cout << "4 - Out only truck" << endl;
		cout << "5 - Out only passenger car" << endl;
		cout << "6 - Multimethod" << endl;
		cout << "7 - Clear and out container" << endl;
		cout << "0 - exit" << endl;
		cin >> k;
		if (cout.fail())
		{
			cout << "Wrong input!" << endl;
			exit(1);
		}
		if (k < 0 || k > 7) {
			cout << "Incorrect choice! Try again!" << endl;
			continue;
		}
		else {
			switch (k)
			{
			case 1:
				Out(c, ofst);
				break;
			case 2:
				cout << "Input number:" << endl;
				cout << "0 - from small to big" << endl;
				cout << "1 - from big to small" << endl;
				while (k1 != 0 || k1 != 1) 
				{
					cin >> k1;
					if (cout.fail())
					{
						cout << "Wrong input!" << endl;
						exit(1);
					}
					if (k1 != 0 || k1 != 1) 
					{
						cout << "Incorrect choice! Try again!" << endl;
						continue;
					}
				}
				switch (k1)
				{
				case 0:
					Sort(c, len, 0);
					break;
				case 1:
					Sort(c, len, 1);
					break;
				default:
					break;
				}
				Out(c, ofst);
				break;
			case 3:
				OutOnlyBus(c, ofst);
				break;
			case 4:
				OutOnlyTruck(c, ofst);
				break;
			case 5:
				OutOnlyPassengerCar(c, ofst);
				break;
			case 6:
				Multimethod(c, ofst);
				break;
			case 7:
				Clear(c);
				Out(c, ofst);
				break;
			default:
				break;
			}
		}
	}
	ifst.close();
	ofst.close();

	cout << "Stop" << endl;
	return 0;
	/*::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();*/
}
