#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;

/*
���� �����ڴ� ��ü�� ���� �����Ǵ� �������� ������ �� �� ȣ���� �ǰ� 
���� �����ڴ� ��ü �� ���� �̹� ���� �� �ʱ�ȭ�� ����� ���¿��� ������ �� �� ȣ���� �ȴ�
*/

class Person
{
private:
	char* name;
	int age;
public:
	Person(char* inname, int inage) :age(inage)
	{
		int len = strlen(inname) + 1;
		name = new char[len];
		strcpy(name, inname);
	}
	void Show()
	{
		cout << name << endl;
		cout << age << endl;
	}
	Person& operator=(Person& man)
	{
		delete[]name;
		age = man.age;
		int len = strlen(man.name) + 1;
		name = new char[len];
		strcpy(name, man.name);
		return *this;
	}
	~Person()
	{
		delete[]name;
		cout << "destructor called" << endl;
	}
};

class BoundCheck //�迭Ŭ����, []������ �����ε�
{
private:
	int* arr;
	int arrlen;
public:
	BoundCheck(int len) :arrlen(len) 
	{
		arr = new int(len);
	}
	int& operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "index out of range" << endl;
			exit(1);
		}
		return arr[idx];//���������� ��ȯ�Ͽ��� ������ ���� ��� �Ӹ��ƴ϶�, ���� ���浵 �����ϴ�.
						//���� index�� ���� ��¸��� ���ϴ� �Լ��� const�Լ��϶� �� �Լ����� ������ ������ �����̴�.
						//���� ��ȯ���� int�� �ϴ� const�Լ��� �����Ͽ� const�Լ� ���������� ���� �Լ� �����ε��� ������ �� �� �ִ�.
	}
	~BoundCheck()
	{
		delete[]arr;
	}
};

int main(void)
{
	BoundCheck array(5);
	for (int i = 0; i < 5; i++)
	{
		array[i] = (i + 1) * 11;//arr[i]�� ��ȯ�޾Ƽ� �������� ���� ���� �����ϴ� �ڵ�.
	}
	for (int i = 0; i < 6; i++)
	{
		cout << array[i] << endl;
	}
	cout << endl;
	return 0;
}