#include<iostream>
#pragma warnings(disable: 4996)

using namespace std;
using std::cin;

class Car
{
private:
	int gasoline_gauge;
public:

	Car(int ga_gauge) :gasoline_gauge(ga_gauge) {}

	int getGasolineGauge()
	{
		return gasoline_gauge;
	}

};

class Hybrid : public Car
{
private:
	int electric_gauge;
public:
	Hybrid(int ga_gauge, int el_gauge) :Car(ga_gauge), electric_gauge(el_gauge) {}
	int getElectricGauge()
	{
		return electric_gauge;
	}
};

class Hywater : public Hybrid
{
private:
	int water_gauge;
public:
	Hywater(int ga_gauge, int el_gauge, int wa_gauge) :Hybrid(ga_gauge, el_gauge), water_gauge(wa_gauge) {}
	int getWaterGauge()
	{
		return water_gauge;
	}
	void show()
	{
		cout << getGasolineGauge() << endl;
		cout << getElectricGauge() << endl;
		cout << getWaterGauge() << endl;
	}
};

int main(void)
{
	Hywater car1(10, 20, 30);
	car1.show();
	cout << endl;
	return 0;
}