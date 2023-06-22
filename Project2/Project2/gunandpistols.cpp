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
	//복사연산자
	Police(Police& ref)
		:handcuffs(ref.handcuffs)
	{
		pistols = new Gun(*(ref.pistols));
		/*
		ref.pistols는 ref의 Gun객체의 주소값을 저장해놓은 Gun* 포인터 이고
		*(ref.pistols)는 그러므로 ref의 Gun객체를 나타낸다.
		new Gun(*(ref.pistols))은 Gun(num)처럼 생성자를 호출하는것이 아닌
		Gun gun1(gun2)처럼 gun1의 복사생성자를 호출하듯
		new Gun(*(ref.pistols))은 복사생성자를 호출하여 객체를 초기화 한것이다.

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
	//대입연산자
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
	Police pol2 = pol1;//복사생성자
	Police pol3(0, 0);
	pol3 = pol1; // 대입연산자
	cout << endl;


		return 0;
}