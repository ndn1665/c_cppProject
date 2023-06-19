//���
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
	int num; // ����Ŭ�������� ���ٰ�����
public:
	Person()// �̷����� void������
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

class Student : public Person //Person�� ����� Student
{//StudentŬ�������� PersonŬ������ private������ ���� ������ �� ����. ���� �Ʒ��� �̴ϼȶ�������, Person�� �Լ��� ���������� �����ؾ� �Ѵ�.
//�׷��ٰ� �ؼ� Person�� private�� ������ ��ӵ��� �ʴ°��� �ƴϴ�.
private:
	char major[50];
public:
	Student(char* myname, int myage, char* mymajor)
		:Person(myage,myname) //����Ŭ������ �̴ϼȶ������� �̿��ؼ� ����Ŭ������ ������ ȣ���� ����� �� �ִ�.
	{						//����Ŭ������ ��ü ������������ ����Ŭ������ �����ڴ� ������ ȣ��ȴ�. ����Ŭ������ �����ڿ��� ����Ŭ������ �����ڸ� ȣ������
							//������, ����Ŭ������ void�����ڰ� ȣ��ȴ�.
							
		strcpy(major, mymajor);
	}
	void ShowInProtected()
	{
		cout << num << endl; //����Ŭ������ �ִ� protected������ �̷��� �ܼ��� ���� �����ϴ�.
	}
	void whoareyou() const
	{
		Whatname(); // ����ϴ� Ŭ������ �Լ��� ����� �� �ִ�.
		whatage();
		cout << "my major is " << major << endl;
	}
};
//����Ŭ������ ��ü�� �Ҹ�� ��, ����Ŭ������ ���� �Ҹ��ϰ�, ����Ŭ������ �� �������� �Ҹ��ϱ� ������
// ����Ŭ�������� �����ڿ��� ���� �Ҵ��� �޸� ������ ���� ����Ŭ�������� �Ҹ��� �ʿ� ����
// ����Ŭ������ �Ҹ��ڿ��� �Ҹ����ָ� �ȴ�.
//����Ŭ���� ���� �ڽ��� ���� �Ҵ��� �޸𸮿� ���ؼ��� �Ҹ��� å���� �ִ�.

class Someone : protected Person // Person���� protected���� ���ٹ����� ���� (ex public����)�� �ִ� �͵��� protected�� ��ȯ �� ����ϰڴٴ� ��.
{};

int main(void)

{
	cout << endl;
	return 0;
}