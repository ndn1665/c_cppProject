#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;

/*
복사 생성자는 객체가 새로 생성되는 시점에서 대입을 할 때 호출이 되고 
대입 연산자는 객체 두 개가 이미 생성 및 초기화가 진행된 상태에서 대입을 할 때 호출이 된다
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

class BoundCheck //배열클래스, []연산자 오버로딩
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
		return arr[idx];//참조값으로 반환하였기 때문에 값의 출력 뿐만아니라, 값의 변경도 가능하다.
						//따라서 index로 값의 출력만을 원하는 함수가 const함수일때 이 함수에서 컴파일 에러가 날것이다.
						//따라서 반환형을 int로 하는 const함수를 선언하여 const함수 선언유무에 따른 함수 오버로딩이 도움이 될 수 있다.
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
		array[i] = (i + 1) * 11;//arr[i]를 반환받아서 참조값을 통해 값을 변경하는 코드.
	}
	for (int i = 0; i < 6; i++)
	{
		cout << array[i] << endl;
	}
	cout << endl;
	return 0;
}