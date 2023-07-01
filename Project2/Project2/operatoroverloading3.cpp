#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0)
		:xpos(x), ypos(y)
	{}
	//�Ű������� default���� ������ new Point[len]�� ���� �� ����.
	//�ֳ��ϸ� ���ڸ� �����ʴ� void�������� ȣ���� ���ؼ� �迭��Ҹ� �̷�� ��ü�� �����Ǳ� �����̴�.
	//���� void�����ڰ� ȣ������� xpos��ypos�� ���� �־��� default���� �־���Ѵ�.
	//Point(void)
	//: xpos(0), ypos(0)
	//{} �ƴϸ� �̷������� �Ű������� ���� void�����ڸ� �����
	friend ostream& operator<<(ostream& os, Point& pos);
};

ostream& operator<<(ostream& os, Point& pos)
{
	os << pos.xpos << "," << pos.ypos << endl;
	return os;
}
typedef Point* Point_ptr;
class BoundedArray
{
private:
	Point_ptr* arr2;
	//Point* arr;
	int arrlen;
public:
	BoundedArray(int len)
		:arrlen(len)
	{
		//	arr = new Point[len];
		arr2 = new Point_ptr[len];
	}
	/*
	Point& operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "index out of range" << endl;
			exit(1);
		}
		return arr[idx];
	}
	*/

	Point_ptr& operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			exit(1);
		}
		return arr2[idx];
	}
};



int main(void)
{
	BoundedArray arr(3);

	//arr[0] = Point(3, 4);//������ ����� ��ü���, ���Կ����ڸ� ����ؾ� �Ѵ�.
	//Point pt(1, 2);
	//arr[1] = pt;
	//cout << arr[0];
	//cout << arr[1];

	arr[0] = new Point(1, 2);
	cout << *arr[0];
	cout << endl;
	return 0;
}
/*

*/