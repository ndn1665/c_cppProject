#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) :xpos(x), ypos(y) {} //�Ű������� default���� ������ new Point[len]�� ���� �� ����.
	//�ֳ��ϸ� ���ڸ� �����ʴ� void�������� ȣ���� ���ؼ� �迭��Ҹ� �̷�� ��ü�� �����Ǳ� �����̴�.
	//���� void�����ڰ� ȣ������� xpos��ypos�� ���� �־��� default���� �־���Ѵ�.
	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << pos.xpos << "," << pos.ypos << endl;
	return os;
}

class BoundCheck
{
private:
	Point* arr;
	int arrlen;
public:
	BoundCheck(int len)
		:arrlen(len)
	{
		arr = new Point[len];
	}
	Point& operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "index out of range" << endl;
			exit(1);
		}
		return arr[idx];
	}
	~BoundCheck()
	{
		delete[]arr;
	}

};

int main(void)
{
	BoundCheck arr(3);
	arr[0] = Point(3, 4);//�ӽð�ü�� �����Ͽ� �迭��� �ʱ�ȭ
	arr[1] = Point(5, 6);
	arr[2] = Point(7, 8);

	cout << arr[0] << endl;

	cout << endl;
	return 0;
}