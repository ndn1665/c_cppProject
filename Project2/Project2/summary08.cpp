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
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	Point operator+(Point pt) // ����Լ������� ������ �����ε�
	{
		Point result;
		result.xpos = xpos + pt.xpos;
		result.ypos = ypos + pt.ypos;
		return result;
	}

	Point operator++()//���׿������� �����ε�
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}

	void show() const
	{
		cout << xpos << endl;
		cout << ypos << endl;
	}
};

Point operator+(Point pt1, Point pt2) //�����Լ������� ������ �����ε� ���, ����Լ������� ������ �����ε��� ���������,
//����Լ� ������ �����ε��� �켱�����̴�.
{
	Point result;
	result.xpos = pt1.xpos + pt2.xpos;
	result.ypos = pt1.ypos + pt2.ypos;
	return result;
}

Point& operator--(Point& ref) // �����Լ����� ���׿������� �����ε�
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}


int main(void)
{
	Point pt1(1, 2);
	Point pt2(3, 4);

	Point pt3 = pt1 + pt2;
	pt3.show();

	cout << endl;
	return 0;
}