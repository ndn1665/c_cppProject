//c++ style ����ȯ

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
	Truck* ptruck1 = dynamic_cast<Truck*>(pcar1);// �����Ͽ��� // ������ ����Ŭ������ �����Լ��� �ϳ��� �����ϴ� ����Ŭ�����̸� �����ϰ���
	Truck* ptruck1 = static_cast<Truck*>(pcar1);// �̰� ����, static_cast�� ���α׷��ӿ��� ���� ���� å���� �ο���

	Car* pcar2 = new Car(50);
	Truck* ptruck2 = dynamic_cast<Truck*>(pcar2);//�����Ͽ��� // �̰� ����Ŭ������ �����Լ��� �����ص� �Ұ���
	//Truck* ptruck2 = static_cast<Truck*>(pcar2); //�̰͵� �������� ���������� ���� �ȵǹǷ� ���α׷��󿡼� ������ ��
	Truck* ptruck3 = new Truck(50, 1000);
	Car* pcar3 = dynamic_cast<Car*>(ptruck3); // dynamic_cast�� ��Ӱ��迡 �ִ� ����Ŭ������ ������ �� ������ �����͸� ����Ŭ������
											//������ �� ������ �����ͷ� ����ȯ�Ҷ� ���
	
	cout << endl;
	return 0;
}