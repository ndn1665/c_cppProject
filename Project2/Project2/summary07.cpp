#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;
//�Լ� �����ε� vs �Լ� �������̵�
//�Լ� �������̵��� ����Ŭ������ ����Ŭ������ ���� �̸��� �Լ��� �����Ͽ� ����Ѵ�. �̶� �Ű��������� ���� �� �Լ� �������̵��� �ȴ�.
//�Ű������� �������̵����� ����Ŭ������ ����Ŭ������ �̸��� ���� �Լ��� �����Ͽ� ����ϸ�, �Լ� �����ε��� �Ǿ�, ����Ŭ������ �Ű����� ���� ���缭 ����ϸ�
//����Ŭ������ �Լ��� ����� �� �ְ� �Ǵ� �Լ� �����ε��� �ȴ�.
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
	virtual void showa() = 0; //���������Լ�, Person��ü�� ��ü������ �뵵�� ������� �ʰ�, ����Ŭ������ ���Ҹ� �ο��ϰ� ������ ����Ѵ�.
	//���������Լ��� ����ϸ�, �Լ��� ��ü�� ����־ �������� ���� Ŭ������ �Ǿ� ��ü������ ���� �� �ִ�.
	//�׸��� ����, Student��ü�� showa��� �����Լ��� ����Ϸ��� ����Ŭ�������� showa��� �����Լ��� ����Ǿ� �־�� �Ѵ�.
	virtual ~Person()
	{
		cout << "~Person" << endl;
	}//virtual�� �Ҹ��ڸ� �����ϸ�, ����Ŭ�������� �Ҹ��ڰ� �۵��Ǿ� ����Ŭ�������� �´�.
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

//�����ڿ����� ����
void Func(const Person& ref); // Person��ü �Ǵ� Person��ü�� ����� ��ü�� ������ ����� ��
							//�Լ� ���ο����� ref�� �����δ� Student�� ����Ű�� �ִٰ� �ص�, ����� �� �ִ� �Լ��� �����Լ� �Ǵ� Person�� �Լ�

int main(void)
{
	Person* ptr;
	ptr = new Person(); // ptr�����ͺ����� ��ü�� �����ϰ� �ִ�. ptr������ ������ Person ��ü  �Ӹ��ƴ϶�, Person��ü�� ����ϰ� �ִ� ����Ŭ������
	//����ų �� �ִ�.
	ptr = new Student(); // aaa�� ������ ������ (���⼭�� Person ��) aaa��ü �Ǵ� aaa�� ������������ ����ϴ� ��� ��ü�� ����ų �� �ִ�. 

	Person* pptr[20];
	//manyptr���� Person��ü�� Student��ü �Ѵ� ���� �� �ִ�. ������ ������ ������ �Ҷ��� �����ʹ� ���������� ���缭 ������ �ϹǷ�, manyptr�� ����Ͽ�
	//Student��ü�� ����� ������ ���� ����.
	Student* sptr[20];
	//�翬������ sptr�δ� Person����� ������ �� �ִ�.

	//Person��ü�� Student��ü�� �����Լ��� �������̵� �Ǿ�������, ������ �����Ͱ� ����Ű�� ��ü�� �Լ��� ȣ���Ѵ�.
	pptr[0] = new Student();
	pptr[0]->showa(); // I am Student ��� // pptr[0]�� ���������� Person������ Student ��ü�� ����Ű�� �ְ�, show�Լ��� �����Լ��̱⶧���� �����ϴ�.

	cout << endl;
	return 0;
}