//c++ style 형변환

#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;

class Car
{
private:
	int fuelGauge;
public:
	Car(int fuel) :fuelGauge(fuel)
	{}
	void ShowFuelGauge() const
	{
		cout << fuelGauge << endl;
	}
};

class Truck : public Car
{
private:
	int freightWeight;
public:
	Truck(int fuel, int weight) : Car(fuel), freightWeight(weight) {}
	void ShowTruckInfo()
	{
		ShowFuelGauge();
		cout << endl;
		cout << freightWeight << endl;
	}
};

int main(void)

{
	//dynamic cast
	Car* pcar1 = new Truck(50, 1000);
	Truck* ptruck1 = dynamic_cast<Truck*>(pcar1);// 컴파일에러 // 하지만 기초클래스가 가상함수를 하나라도 포함하는 기초클래스이면 컴파일가능
	Truck* ptruck1 = static_cast<Truck*>(pcar1);// 이건 가능, static_cast는 프로그래머에게 보다 많은 책임을 부여함

	Car* pcar2 = new Car(50);
	Truck* ptruck2 = dynamic_cast<Truck*>(pcar2);//컴파일에러 // 이건 기초클래스가 가상함수를 포함해도 불가능
	//Truck* ptruck2 = static_cast<Truck*>(pcar2); //이것도 컴파일은 가능하지만 말이 안되므로 프로그램상에서 오류가 남
	Truck* ptruck3 = new Truck(50, 1000);
	Car* pcar3 = dynamic_cast<Car*>(ptruck3); // dynamic_cast는 상속관계에 있는 유도클래스의 포인터 및 참조형 데이터를 기초클래스의
											//포인터 및 참조형 데이터로 형변환할때 사용
	
	cout << endl;
	return 0;
}