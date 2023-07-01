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
	//매개변수의 default값이 없으면 new Point[len]을 해줄 수 없다.
	//왜냐하면 인자를 받지않는 void생성자의 호출을 통해서 배열요소를 이루는 객체가 생성되기 때문이다.
	//따라서 void생성자가 호출됐을때 xpos와ypos에 값을 넣어줄 default값이 있어야한다.
	//Point(void)
	//: xpos(0), ypos(0)
	//{} 아니면 이런식으로 매개변수가 없는 void생성자를 만들기
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

	//arr[0] = Point(3, 4);//저장의 대상이 객체라면, 대입연산자를 사용해야 한다.
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