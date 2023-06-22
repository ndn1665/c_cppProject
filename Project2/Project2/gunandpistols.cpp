#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;

class Gun
{
public:
	int bullets;
public:
	Gun(int num) :bullets(num) {}
	void shot()
	{
		cout << "bang" << endl;
		bullets--;
	}
};

class Police
{
public:
	int handcuffs;
	Gun* pistols;
public:
	Police(int num1, int num2) :handcuffs(num1)
	{
		if (num2 > 0)
		{
			pistols = new Gun(num2);
		}
		else
		{
			pistols = NULL;
		}
	}
	//���翬����
	Police(Police& ref)
		:handcuffs(ref.handcuffs)
	{
		pistols = new Gun(*(ref.pistols));
		/*
		ref.pistols�� ref�� Gun��ü�� �ּҰ��� �����س��� Gun* ������ �̰�
		*(ref.pistols)�� �׷��Ƿ� ref�� Gun��ü�� ��Ÿ����.
		new Gun(*(ref.pistols))�� Gun(num)ó�� �����ڸ� ȣ���ϴ°��� �ƴ�
		Gun gun1(gun2)ó�� gun1�� ��������ڸ� ȣ���ϵ�
		new Gun(*(ref.pistols))�� ��������ڸ� ȣ���Ͽ� ��ü�� �ʱ�ȭ �Ѱ��̴�.

		ex>
			class simple
			{
			private:
				int num;
			public:
				simple(int n) :num(n) {};
				void show()const {cout << num << endl;}
			};
			int main(void)
			{
				simple sim1(1);
				simple* sim2 = new simple(sim1);
				sim2->show();
				return 0;
			}
		*/
	}
	//���Կ�����
	Police& operator=(Police& pol)
	{
		handcuffs = pol.handcuffs;
		pistols = new Gun(*(pol.pistols));
		return *this;
	}
	void shot()
	{
		if (pistols == NULL)
		{
			cout << "hut Bang" << endl;
		}
		else
		{
			pistols->shot();
		}
	}
	~Police()
	{
		if (pistols != NULL)
		{
			delete pistols;
		}

	}


};

int main(void)
{
	Police pol1(10, 5);
	Police pol2 = pol1;//���������
	Police pol3(0, 0);
	pol3 = pol1; // ���Կ�����
	cout << endl;


		return 0;
}