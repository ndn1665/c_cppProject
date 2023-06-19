#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;

class Rectangle
{
private:
	int x;
	int y;
public:
	Rectangle(int inx, int iny)
		:x(inx), y(iny)
	{}
	void ShowAreaInfo()
	{
		cout << "result : " << x * y << endl;
	}
};

class Square : public Rectangle
{
private:
	int r;
public:
	Square(int inr)
		:Rectangle(inr, inr)
	{}
};

int main(void)
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();
	Square sqr(7);
	sqr.ShowAreaInfo();
	cout << endl;
	return 0;
}