#include<iostream>

class Car
{
//protected: ��Ӱ��迡�� ����Ŭ���������� ���� ���
private://Ŭ����������(Ŭ�������� ���ǵ� �Լ�)���� ���
	int num;
	const Point pt;
public://��𼭵� ���� ���
	Car(int n,int xpos,int ypos)//������, �����ڵ� �Լ��� �����̹Ƿ� �����ε��� ������. ���� Car(void) �̷� �Լ��� �����ڸ� ���ÿ� ���� �� ����.
		:pt(xpos,ypos) // ��� �̴ϼȶ�����,Car�� ���޵� ���ڵ�� ��������� ������ ȣ�⿡ ���.(��������� ��ü�� �ƴϾ ����)
	{					//���� �����ڷδ� const�������(���� ������ ����)�� �ʱ�ȭ �� �� �ִ�. 
		num = n;
	}
	Car()//�����ڸ� ��������Ƿ� ��ü������������ ������ ������ ����Ѵ�.ex>
		//Car car1(10) or Car car1//�ι�°�� ���ڷ� void�� �༭ �����ε��� Car()�� �����ڷ� ���°�.
	{
		num = 0;
	}

	class AAA
	{
	private:
		int num;
		char* name;
	public:	
		AAA(int len) :num(0)
		{
			name = new char[len + 1];
		}
		AAA& CreateInitObj(int n) const
		{
			AAA* ptr = new AAA(n); // �Ʒ��� �ִ� private�����ڷ� ��ü ������ �����ϰ���.(private�����ڴ� Ŭ���� ���ο����� ���� ����)
			return *ptr;
		}
		AAA& returnthis()
		{
			return *this;//this �����ʹ� ��ü�� ����Ű��, this �� ��ü�� �ּҰ��� ����ִ�.
		}
		~AAA()
		{
			delete[]name; // �����ڿ��� �Ҵ��� ���ҽ� ������ ���� �Ҹ��ڿ��� ���ش�
		}
	private:
		AAA(int n) :num(n) {} 
	};


	void shownum() const; // const �Լ��� ��������� ���� �������� �ʰڴٴ� ���̴�.
							// const �Լ������� �ٸ� �Լ��� ȣ���Ҷ� ȣ��Ǵ� �Լ����� const�Լ������Ѵ�.(��������� ���� �������� �ʴ� �Լ�����)
	void shownum2(const Car& easy)
	{
		num = easy.func(); // easy�� const�������̰� const�����ڸ� ������� ���� ����ɷ��� ���� �Լ��� ȣ���� ������� �ʴ´�.
							//���� const�����ڴ� const�Լ��� ȣ���� ������ ���̴�,
	}

};
int main()
{
	AAA base;
	AAA& obj1 = base.CreateInitObj(3);//private �����ڷ� �����ϴ� ��//�����ڸ� ��ȯ�ϹǷ� �����ڷ� �޵��� �ڵ��ۼ�

	delete &obj1; //new AAA(n)�� �߱⶧���� ������
	/*
	delete�� �⺻������ delete ptró�� �����Ͱ� ������ �޸𸮰����� �����ٶ� ptr�� ����Ű�� �ּҸ� �޴´� .(delete 000x01e120�̷�����)
	�ٵ� obj1�� ����ó�� ���ǹǷ� &obj1�� obj1�� �ּҸ� ����Ͽ� delete������Ѵ�.
	*/

	return 0;
}