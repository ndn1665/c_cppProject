#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) :xpos(x), ypos(y) {} //매개변수의 default값이 없으면 new Point[len]을 해줄 수 없다.
	//왜냐하면 인자를 받지않는 void생성자의 호출을 통해서 배열요소를 이루는 객체가 생성되기 때문이다.
	//따라서 void생성자가 호출됐을때 xpos와ypos에 값을 넣어줄 default값이 있어야한다.
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
	arr[0] = Point(3, 4);//임시객체를 생성하여 배열요소 초기화
	arr[1] = Point(5, 6);
	arr[2] = Point(7, 8);

	cout << arr[0] << endl;

	cout << endl;
	return 0;
}