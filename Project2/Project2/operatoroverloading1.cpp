#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;

class Point
{
private:
	int xpos;
	int ypos;
public:

	Point(int x, int y) :xpos(x), ypos(y) {}

	friend Point& operator-(Point& pt1, Point pt2);
	friend bool operator==(Point pt1, Point pt2);
	friend bool operator!=(Point pt1, Point pt2);

	operator++();//��������//++pt �̷������� ��� ����
	operator++(int); //��������, int�� �ǹ̴� ũ�Ծ���. ���� ��������� ���������� �����ϱ� ���Ѱ�//pt++�̷��� ��� ����,�����Լ��������� ��
					//�������� �Ű������� int ���ָ� �ȴ�.


	//�ڷ����� �ٸ� �� ��ü�� ��ȯ��Ģ�� �����ϵ��� �ϴ¿����ε�
	Point& operator*(int times)
	{
		xpos = xpos * times;
		ypos = ypos * times;
		return *this;
	} 
	


	Point& operator+=(Point pt)
	{
		xpos += pt.xpos;
		ypos += pt.ypos;
		return *this;
	}

	Point& operator-=(Point pt)
	{
		xpos -= pt.xpos;
		ypos -= pt.ypos;
		return *this;
	}


	void Show() const
	{
		cout << xpos << endl;
		cout << ypos << endl;
	}
};

Point& operator-(Point& pt1, Point pt2)
{
	pt1.xpos -= pt2.xpos;
	pt1.ypos -= pt2.ypos;
	return pt1;
}

bool operator==(Point pt1, Point pt2)
{
	if ((pt1.xpos == pt2.xpos) && (pt1.ypos == pt2.ypos))
	{
		return true;
	}
	return false;
}

bool operator!=(Point pt1, Point pt2)
{
	if ((pt1 == pt2) == true)
	{
		return false;
	}
	return true;
}
// operator*�� pt*times �� ���������� times*pt�� �Ұ����� �ڵ�
//���� �Ʒ��� ���� ���� �ڵ带 �̿��Ͽ�, ��ȯ��Ģ�� �����ϵ��� �� �� �ִ�.

Point operator*(int times, Point& ref)
{
	return ref * times; // ref*times�� ref.operator*(times)ȣ��
}

int main(void)
{
	Point pt1(10, 20);
	Point pt2(1, 2);
	pt1 - pt2;
	pt1.Show();
	pt1 += pt2;
	pt1.Show();
	pt1 -= pt2;
	pt1.Show();
	cout << (pt1 == pt2) << endl;
	cout << (pt1 != pt2) << endl;

	cout << endl;
	return 0;
}