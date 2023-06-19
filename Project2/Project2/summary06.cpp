//상속
#include<iostream>
#pragma warnings(disable: 4996)

using namespace std;
using std::cin;

class Person
{
private:
	int age;
	char name[50];
protected:
	int num; // 유도클래스에서 접근가능함
public:
	Person()// 이런것이 void생성자
		:age(30) 
	{}
	Person(int myage, char* myname)
		:age(myage)
	{
		strcpy(name, myname);
	}
	void Whatname() const
	{
		cout << "my name is " << name << endl;
	}
	void whatage() const
	{
		cout << "im " << age << endl;
	}
};

class Student : public Person //Person을 상속한 Student
{//Student클래스에서 Person클래스의 private영역에 직접 진입할 수 없다. 따라서 아래의 이니셜라이저나, Person의 함수로 간접적으로 접근해야 한다.
//그렇다고 해서 Person의 private한 영역이 상속되지 않는것은 아니다.
private:
	char major[50];
public:
	Student(char* myname, int myage, char* mymajor)
		:Person(myage,myname) //유도클래스는 이니셜라이저를 이용해서 기초클래스의 생성자 호출을 명시할 수 있다.
	{						//유도클래스의 객체 생성과정에서 기초클래스의 생성자는 무조건 호출된다. 유도클래스의 생성자에서 기초클래스의 생성자를 호출하지
							//않으면, 기초클래스의 void생성자가 호출된다.
							
		strcpy(major, mymajor);
	}
	void ShowInProtected()
	{
		cout << num << endl; //기초클래스에 있는 protected영역에 이렇게 단순히 접근 가능하다.
	}
	void whoareyou() const
	{
		Whatname(); // 상속하는 클래스의 함수를 사용할 수 있다.
		whatage();
		cout << "my major is " << major << endl;
	}
};
//유도클래스의 객체가 소멸될 땐, 유도클래스가 먼저 소멸하고, 기초클래스가 그 다음으로 소멸하기 때문에
// 기초클래스에서 생성자에서 동적 할당한 메모리 공간은 굳이 유도클래스에서 소멸할 필요 없이
// 기초클래스의 소멸자에서 소멸해주면 된다.
//유도클래스 또한 자신이 동적 할당한 메모리에 대해서만 소멸의 책임이 있다.

class Someone : protected Person // Person에서 protected보다 접근범위가 넓은 (ex public영역)에 있는 것들을 protected로 변환 후 상속하겠다는 뜻.
{};

int main(void)

{
	cout << endl;
	return 0;
}