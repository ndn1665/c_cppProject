#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;
//함수 오버로딩 vs 함수 오버라이딩
//함수 오버라이딩은 유도클래스에 기초클래스와 같은 이름의 함수를 정의하여 사용한다. 이때 매개변수조차 같을 때 함수 오버라이딩이 된다.
//매개변수의 갯수차이 등을 차이로 유도클래스에 기초클래스와 이름이 같은 함수를 정의하여 사용하면, 함수 오버로딩이 되어, 
//기초클래스의 매개변수 수로 맞춰서 함수를 사용하면 기초클래스의 함수도 충분히 사용할 수 있게 해주는 함수 오버로딩이 된다.
class Person
{
private:
	int num;
public:
	Person(int innum) :num(innum) {};

	void show()
	{
		cout << "I am Person" << endl;
	}
	virtual void showa() = 0; //순수가상함수, Person객체를 객체생성의 용도로 사용하지 않고, 기초클래스의 역할만 부여하고 싶을때 사용한다.
	//순수가상함수를 사용하면, 함수의 몸체가 비어있어서 완전하지 않은 클래스가 되어 객체생성을 막을 수 있다.
	//그리고 또한, Student객체의 showa라는 가상함수를 사용하려면 기초클래스에도 showa라는 가상함수가 선언되어 있어야 한다.
	virtual ~Person()
	{
		cout << "~Person" << endl;
	}//virtual로 소멸자를 생성하면, 유도클래스부터 소멸자가 작동되어 기초클래스까지 온다.
		//이는 Person *ptr = new Student(); 이런상황에서
		// delete ptr을 하였을때 Student객체의 소멸자가 호출되지않는 상황을 방지한다.
};

class Student : public Person
{
private:
	int study;
public:
	Student(int innum, int instudy) :Person(innum), study(instudy) {};
	virtual void showa()
	{
		cout << "I am Student" << endl;
	}
	virtual ~Student()
	{
		cout << "~Student" << endl;
	}
};

//참조자에서의 예시
void Func(const Person& ref); // Person객체 또는 Person객체를 상속한 객체가 인자의 대상이 됨
							//함수 내부에서는 ref가 실제로는 Student를 가리키고 있다고 해도, 사용할 수 있는 함수는 가상함수 또는 Person의 함수

int main(void)
{
	Person* ptr;
	ptr = new Person(); // ptr포인터변수가 객체를 참조하고 있다. ptr포인터 변수는 Person 객체  뿐만아니라, Person객체를 상속하고 있는 유도클래스도
	//가리킬 수 있다.
	ptr = new Student(); // aaa형 포인터 변수는 (여기서는 Person 형) aaa객체 또는 aaa를 직간접적으로 상속하는 모든 객체를 가리킬 수 있다. 

	Person* pptr[20];
	//pptr에는 Person객체와 Student객체 둘다 담을 수 있다. 하지만 포인터 연산을 할때는 포인터는 포인터형에 맞춰서 연산을 하므로, 
	// pptr을 사용하여 Student객체의 멤버에 접근할 수는 없다.
	/*
	class first가 있고, second 는 first를 상속하며, second의 1,2는 first의 생성자로 들어간다고할때,
	class second(1,2,3,4)에서
	first& ref = new second(1,2,3,4)라고 할때
	ref는 second객체의 1,2에는 접근할 수 있다. 왜냐하면 first의 영역이기 때문.
	하지만 3과4에는 접근할 수없다. 자료형이 first이기 때문에.
	ex>
	second sec(1, 2, 3, 4);
	first* ptr = &sec;
	ptr->num1;
	ptr->num2;
	ptr->num3;//오류
	ptr->num4;//오류
	*/
	
	
	
	Student* sptr[20];
	//당연하지만 sptr로는 Person멤버에 접근할 수 있다.

	//Person객체와 Student객체에 가상함수가 오버라이딩 되어있을땐, 실제로 포인터가 가리키는 객체의 함수를 호출한다.
	pptr[0] = new Student();
	pptr[0]->showa(); // I am Student 출력 // pptr[0]의 포인터형은 Person이지만 Student 객체를 가리키고 있고, show함수는 가상함수이기때문에 가능하다.

	cout << endl;
	return 0;
}