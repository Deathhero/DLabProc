#include <iostream>
#include <fstream>
#include "Bus.h"
#include "Truck.h"
#include "PassengerCar.h"
//#include "Car.h"
#include "FilesCmp.h"

using namespace std;

float FuncBus(bus* &b);
void InBus(bus* &b, ifstream &ifst);
void OutBus(bus* &b, ofstream &ofst);

class BusTest : public ::testing::Test {
};

TEST_F(BusTest, CheckFuncBusDivisionByZero) {
	bus *b = new bus;
	b->enginepower = 0;
	b->passengercapacity = 1;
	float expected = 0;
	ASSERT_NEAR(expected, FuncBus(b), 0.01);
}

TEST_F(BusTest, CheckFuncBus) {
	bus *b = new bus;
	b->enginepower = 4;
	b->passengercapacity = 2;
	float expected = 37.5;
	ASSERT_NEAR(expected, FuncBus(b), 0.01);
}


TEST_F(BusTest, CheckInput) {
	ifstream ifst("InBus.txt");
	bus* actual = new bus;
	InBus(actual, ifst);
	bus b;
	b.enginepower = 1;
	b.fuelconsumption = 2.5;
	b.passengercapacity = 3;
	ASSERT_EQ(actual->enginepower, b.enginepower);
	ASSERT_NEAR(actual->fuelconsumption, b.fuelconsumption, 0.01);
	ASSERT_EQ(actual->passengercapacity, b.passengercapacity);
}

TEST_F(BusTest, CheckOutput) {
	ofstream ofst("OutTest.txt");
	bus *b = new bus;
	b->enginepower = 1;
	b->fuelconsumption = 2.5;
	b->passengercapacity = 3;
	OutBus(b, ofst);
	ofst.close();

	ifstream expected("OutBus.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}


//##########################################################################################################
//##########################################################################################################

float FuncTruck(truck* &t);
void InTruck(truck* &t, ifstream &ifst);
void OutTruck(truck* &t, ofstream &ofst);

class TruckTest : public ::testing::Test {
};

TEST_F(TruckTest, CheckFuncTruckDivisionByZero) {
	truck *t = new truck;
	t->enginepower = 0;
	t->carryingcapacity = 1;
	float expected = 0;
	ASSERT_NEAR(expected, FuncTruck(t), 0.01);
}

TEST_F(TruckTest, CheckFuncTruck) {
	truck *t = new truck;
	t->enginepower = 2;
	t->carryingcapacity = 3;
	float expected = 1.5;
	ASSERT_NEAR(expected, FuncTruck(t), 0.01);
}

TEST_F(TruckTest, CheckInput) {
	ifstream ifst("InTruck.txt");
	truck* actual = new truck;
	InTruck(actual, ifst);
	truck t;
	t.enginepower = 1;
	t.fuelconsumption = 2.5;
	t.carryingcapacity = 3;
	ASSERT_EQ(actual->enginepower, t.enginepower);
	ASSERT_NEAR(actual->fuelconsumption, t.fuelconsumption, 0.01);
	ASSERT_EQ(actual->carryingcapacity, t.carryingcapacity);
}

TEST_F(TruckTest, CheckOutput) {
	ofstream ofst("OutTest.txt");
	truck *t = new truck;
	t->enginepower = 1;
	t->fuelconsumption = 2.5;
	t->carryingcapacity = 3;
	OutTruck(t, ofst);
	ofst.close();

	ifstream expected("OutTruck.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}
//##########################################################################################################
//##########################################################################################################

float FuncPassengerCar(passengercar* &p);
void InPassengercar(passengercar* &p, ifstream &ifst);
void OutPassengercar(passengercar* &p, ofstream &ofst);

class PassengerCarTest : public ::testing::Test {
};

TEST_F(PassengerCarTest, CheckFuncPassengerCarDivisionByZero) {
	passengercar *p = new passengercar;
	p->enginepower = 0;
	p->maxspeed = 1;
	float expected = 0;
	ASSERT_NEAR(expected, FuncPassengerCar(p), 0.01);
}

TEST_F(PassengerCarTest, CheckFuncPassengerCar) {
	passengercar *p = new passengercar;
	p->enginepower = 2;
	p->maxspeed = 3;
	float expected = 1.5;
	ASSERT_NEAR(expected, FuncPassengerCar(p), 0.01);
}

TEST_F(PassengerCarTest, CheckInput) {
	ifstream ifst("InPassengerCar.txt");
	passengercar* actual = new passengercar;
	InPassengercar(actual, ifst);
	passengercar p;
	p.enginepower = 1;
	p.fuelconsumption = 2.5;
	p.maxspeed = 3;
	ASSERT_EQ(actual->enginepower, p.enginepower);
	ASSERT_NEAR(actual->fuelconsumption, p.fuelconsumption, 0.01);
	ASSERT_EQ(actual->maxspeed, p.maxspeed);
}

TEST_F(PassengerCarTest, CheckOutput) {
	ofstream ofst("OutTest.txt");
	passengercar *p = new passengercar;
	p->enginepower = 1;
	p->fuelconsumption = 2.5;
	p->maxspeed = 3;
	OutPassengercar(p, ofst);
	ofst.close();

	ifstream expected("OutPassengerCar.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

//##########################################################################################################
//##########################################################################################################

car* In(ifstream &ifst);
void Out(car *a, ofstream &ofst);
bool Compare(car *c1, car *c2);

class CarTest : public ::testing::Test {
};

TEST_F(CarTest, CheckInputBus) {
	ifstream ifst("CarInBus.txt");
	bus* actual = (bus *)In(ifst);

	bus* expected = new bus;
	expected->k = bus::key::BUS;
	expected->enginepower = 1;
	expected->fuelconsumption = 2.5;
	expected->passengercapacity = 3;

	ASSERT_TRUE(expected->k == actual->k);
	ASSERT_EQ(actual->enginepower, expected->enginepower);
	ASSERT_NEAR(actual->fuelconsumption, expected->fuelconsumption, 0.01);
	ASSERT_EQ(actual->passengercapacity, expected->passengercapacity);
}

TEST_F(CarTest, CheckInputTruck) {
	ifstream ifst("CarInTruck.txt");
	truck* actual = (truck *)In(ifst);

	truck* expected = new truck;
	expected->k = truck::key::TRUCK;
	expected->enginepower = 1;
	expected->fuelconsumption = 2.5;
	expected->carryingcapacity = 3;

	ASSERT_TRUE(expected->k == actual->k);
	ASSERT_EQ(actual->enginepower, expected->enginepower);
	ASSERT_NEAR(actual->fuelconsumption, expected->fuelconsumption, 0.01);
	ASSERT_EQ(actual->carryingcapacity, expected->carryingcapacity);
}

TEST_F(CarTest, CheckInputPassengerCar) {
	ifstream ifst("CarInPassengerCar.txt");
	passengercar* actual = (passengercar *)In(ifst);

	passengercar* expected = new passengercar;
	expected->k = passengercar::key::PASSENGERCAR;
	expected->enginepower = 1;
	expected->fuelconsumption = 2.5;
	expected->maxspeed = 3;

	ASSERT_TRUE(expected->k == actual->k);
	ASSERT_EQ(actual->enginepower, expected->enginepower);
	ASSERT_NEAR(actual->fuelconsumption, expected->fuelconsumption, 0.01);
	ASSERT_EQ(actual->maxspeed, expected->maxspeed);
}

TEST_F(CarTest, CheckOutputBus) {
	ofstream ofst("OutTest.txt");

	bus* b = new bus;
	b->k = bus::key::BUS;
	b->enginepower = 1;
	b->fuelconsumption = 2.5;
	b->passengercapacity = 3;

	Out((car *)b, ofst);
	ofst.close();

	ifstream expected("CarOutBus.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(CarTest, CheckOutputTruck) {
	ofstream ofst("OutTest.txt");

	truck* t = new truck;
	t->k = truck::key::TRUCK;
	t->enginepower = 1;
	t->fuelconsumption = 2.5;
	t->carryingcapacity = 3;

	Out((car *)t, ofst);
	ofst.close();

	ifstream expected("CarOutTruck.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(CarTest, CheckOutputPassengerCar) {
	ofstream ofst("OutTest.txt");

	passengercar* p = new passengercar;
	p->k = passengercar::key::PASSENGERCAR;
	p->enginepower = 1;
	p->fuelconsumption = 2.5;
	p->maxspeed = 3;

	Out((car *)p, ofst);
	ofst.close();

	ifstream expected("CarOutPassengerCar.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(CarTest, CheckCompare) {
	bus* b1 = new bus;
	b1->k = bus::key::BUS;
	b1->enginepower = 1;
	b1->passengercapacity = 3;

	bus* b2 = new bus;
	b2->k = bus::key::BUS;
	b2->enginepower = 1;
	b2->passengercapacity = 2;

	ASSERT_TRUE(Compare((car*)b1, (car *)b2));
}

//#############################################################################################
//#############################################################################################

struct container *Init();
void Clear(container* &cont);
int In(container* &cont, ifstream &inFile);
void Out(container* &cont, ofstream &outFile);
void Sort(container* &cont, int len);
void OutOnlyBus(container* &cont, ofstream &outFile);
void OutOnlyTruck(container* &cont, ofstream &outFile);
void OutOnlyPassengerCar(container* &cont, ofstream &outFile);

class ContainerTest : public ::testing::Test {
};

TEST_F(ContainerTest, CheckInitContainer) {

	container *c;
	c = Init();
	
	ASSERT_EQ(c->len, 0);
	ASSERT_TRUE(c->cont == NULL);
	ASSERT_TRUE(c->next == NULL);
	ASSERT_TRUE(c->prev == NULL);
}

TEST_F(ContainerTest, CheckClearEmptyContainer) {

	container *c;
	c = Init();

	Clear(c);

	ASSERT_EQ(c->len, 0);
	ASSERT_TRUE(c->cont == NULL);
	ASSERT_TRUE(c->next == NULL);
	ASSERT_TRUE(c->prev == NULL);
}

TEST_F(ContainerTest, CheckClearContainer) {
	container *c;
	c = Init();

	bus* b = new bus;
	
	container *temp;
	temp = new container;
	temp->cont = (car*)b;
	temp->len =  1;
	temp->next = NULL;
	temp->prev = c;
	c = temp;

	Clear(c);

	ASSERT_EQ(c->len, 0);
	ASSERT_TRUE(c->cont == NULL);
	ASSERT_TRUE(c->next == NULL);
	ASSERT_TRUE(c->prev == NULL);
}

TEST_F(ContainerTest, CheckOutBus) {
	ofstream ofst("OutTest.txt");

	container *c;
	c = Init();

	bus* b = new bus;
	b->k = bus::key::BUS;
	b->enginepower = 1;
	b->fuelconsumption = 2.5;
	b->passengercapacity = 3;

	truck *t = new truck;
	t->k = truck::key::TRUCK;
	t->enginepower = 1;
	t->fuelconsumption = 2.5;
	t->carryingcapacity = 3;

	passengercar *p = new passengercar;
	p->k = passengercar::key::PASSENGERCAR;
	p->enginepower = 1;
	p->fuelconsumption = 2.5;
	p->maxspeed = 3;

	container *temp, *prev;
	temp = new container;
	prev = c->next;
	c->next = temp;
	temp->cont = (car*)b;
	temp->len = 1;
	temp->next = prev;
	temp->prev = c;
	if (prev != NULL)
	{
		prev->prev = temp;
	}
	c = temp;

	temp = new container;
	prev = c->next;
	c->next = temp;
	temp->cont = (car*)t;
	temp->len = 2;
	temp->next = prev;
	temp->prev = c;
	if (prev != NULL)
	{
		prev->prev = temp;
	}
	c = temp;

	temp = new container;
	prev = c->next;
	c->next = temp;
	temp->cont = (car*)p;
	temp->len = 3;
	temp->next = prev;
	temp->prev = c;
	if (prev != NULL)
	{
		prev->prev = temp;
	}
	c = temp;

	OutOnlyBus(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerOutBus.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckOutTruck) {
	ofstream ofst("OutTest.txt");

	container *c;
	c = Init();

	bus* b = new bus;
	b->k = bus::key::BUS;
	b->enginepower = 1;
	b->fuelconsumption = 2.5;
	b->passengercapacity = 3;

	truck *t = new truck;
	t->k = truck::key::TRUCK;
	t->enginepower = 1;
	t->fuelconsumption = 2.5;
	t->carryingcapacity = 3;

	passengercar *p = new passengercar;
	p->k = passengercar::key::PASSENGERCAR;
	p->enginepower = 1;
	p->fuelconsumption = 2.5;
	p->maxspeed = 3;

	container *temp, *prev;
	temp = new container;
	prev = c->next;
	c->next = temp;
	temp->cont = (car*)b;
	temp->len = 1;
	temp->next = prev;
	temp->prev = c;
	if (prev != NULL)
	{
		prev->prev = temp;
	}
	c = temp;

	temp = new container;
	prev = c->next;
	c->next = temp;
	temp->cont = (car*)t;
	temp->len = 2;
	temp->next = prev;
	temp->prev = c;
	if (prev != NULL)
	{
		prev->prev = temp;
	}
	c = temp;

	temp = new container;
	prev = c->next;
	c->next = temp;
	temp->cont = (car*)p;
	temp->len = 3;
	temp->next = prev;
	temp->prev = c;
	if (prev != NULL)
	{
		prev->prev = temp;
	}
	c = temp;

	OutOnlyTruck(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerOutTruck.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckOutPassengerCar) {
	ofstream ofst("OutTest.txt");

	container *c;
	c = Init();

	bus* b = new bus;
	b->k = bus::key::BUS;
	b->enginepower = 1;
	b->fuelconsumption = 2.5;
	b->passengercapacity = 3;

	truck *t = new truck;
	t->k = truck::key::TRUCK;
	t->enginepower = 1;
	t->fuelconsumption = 2.5;
	t->carryingcapacity = 3;

	passengercar *p = new passengercar;
	p->k = passengercar::key::PASSENGERCAR;
	p->enginepower = 1;
	p->fuelconsumption = 2.5;
	p->maxspeed = 3;

	container *temp, *prev;
	temp = new container;
	prev = c->next;
	c->next = temp;
	temp->cont = (car*)b;
	temp->len = 1;
	temp->next = prev;
	temp->prev = c;
	if (prev != NULL)
	{
		prev->prev = temp;
	}
	c = temp;

	temp = new container;
	prev = c->next;
	c->next = temp;
	temp->cont = (car*)t;
	temp->len = 2;
	temp->next = prev;
	temp->prev = c;
	if (prev != NULL)
	{
		prev->prev = temp;
	}
	c = temp;

	temp = new container;
	prev = c->next;
	c->next = temp;
	temp->cont = (car*)p;
	temp->len = 3;
	temp->next = prev;
	temp->prev = c;
	if (prev != NULL)
	{
		prev->prev = temp;
	}
	c = temp;

	OutOnlyPassengerCar(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerOutPassengerCar.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckSort) {
	ofstream ofst("OutTest.txt");

	container *c;
	c = Init();

	bus* b = new bus;
	b->k = bus::key::BUS;
	b->enginepower = 1;
	b->fuelconsumption = 2.5;
	b->passengercapacity = 3;

	truck *t = new truck;
	t->k = truck::key::TRUCK;
	t->enginepower = 1;
	t->fuelconsumption = 2.5;
	t->carryingcapacity = 3;

	passengercar *p = new passengercar;
	p->k = passengercar::key::PASSENGERCAR;
	p->enginepower = 1;
	p->fuelconsumption = 2.5;
	p->maxspeed = 3;

	container *temp, *prev;
	temp = new container;
	prev = c->next;
	c->next = temp;
	temp->cont = (car*)b;
	temp->len = 1;
	temp->next = prev;
	temp->prev = c;
	if (prev != NULL)
	{
		prev->prev = temp;
	}
	c = temp;

	temp = new container;
	prev = c->next;
	c->next = temp;
	temp->cont = (car*)t;
	temp->len = 2;
	temp->next = prev;
	temp->prev = c;
	if (prev != NULL)
	{
		prev->prev = temp;
	}
	c = temp;

	temp = new container;
	prev = c->next;
	c->next = temp;
	temp->cont = (car*)p;
	temp->len = 3;
	temp->next = prev;
	temp->prev = c;
	if (prev != NULL)
	{
		prev->prev = temp;
	}
	c = temp;

	Sort(c, 3);
	Out(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerSort.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckSortEmpty) {
	ofstream ofst("OutTest.txt");

	container *c;
	c = Init();

	Sort(c, 0);
	Out(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerSortEmpty.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckSortEqual) {
	ofstream ofst("OutTest.txt");

	container *c;
	c = Init();

	truck *t = new truck;
	t->k = truck::key::TRUCK;
	t->enginepower = 1;
	t->fuelconsumption = 2.5;
	t->carryingcapacity = 3;

	passengercar *p = new passengercar;
	p->k = passengercar::key::PASSENGERCAR;
	p->enginepower = 1;
	p->fuelconsumption = 2.5;
	p->maxspeed = 3;

	container *temp, *prev;
	temp = new container;

	temp = new container;
	prev = c->next;
	c->next = temp;
	temp->cont = (car*)t;
	temp->len = 1;
	temp->next = prev;
	temp->prev = c;
	if (prev != NULL)
	{
		prev->prev = temp;
	}
	c = temp;

	temp = new container;
	prev = c->next;
	c->next = temp;
	temp->cont = (car*)p;
	temp->len = 2;
	temp->next = prev;
	temp->prev = c;
	if (prev != NULL)
	{
		prev->prev = temp;
	}
	c = temp;

	Sort(c, 2);
	Out(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerSortEqual.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckOut) {
	ofstream ofst("OutTest.txt");

	container *c;
	c = Init();

	bus* b = new bus;
	b->k = bus::key::BUS;
	b->enginepower = 1;
	b->fuelconsumption = 2.5;
	b->passengercapacity = 3;

	truck *t = new truck;
	t->k = truck::key::TRUCK;
	t->enginepower = 1;
	t->fuelconsumption = 2.5;
	t->carryingcapacity = 3;

	passengercar *p = new passengercar;
	p->k = passengercar::key::PASSENGERCAR;
	p->enginepower = 1;
	p->fuelconsumption = 2.5;
	p->maxspeed = 3;

	container *temp, *prev;
	temp = new container;
	prev = c->next;
	c->next = temp;
	temp->cont = (car*)b;
	temp->len = 1;
	temp->next = prev;
	temp->prev = c;
	if (prev != NULL)
	{
		prev->prev = temp;
	}
	c = temp;

	temp = new container;
	prev = c->next;
	c->next = temp;
	temp->cont = (car*)t;
	temp->len = 2;
	temp->next = prev;
	temp->prev = c;
	if (prev != NULL)
	{
		prev->prev = temp;
	}
	c = temp;

	temp = new container;
	prev = c->next;
	c->next = temp;
	temp->cont = (car*)p;
	temp->len = 3;
	temp->next = prev;
	temp->prev = c;
	if (prev != NULL)
	{
		prev->prev = temp;
	}
	c = temp;

	Out(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerOut.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}