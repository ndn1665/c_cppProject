#include<iostream>
#pragma warning(disable: 4996)

using namespace std;

class Point
{
private:
	int xpos;
	int ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	friend istream& operator>>(istream&, Point&);
	friend ostream& operator<<(ostream&, const Point&);
};

istream& operator>>(istream& is, Point& pt)
{
	is >> pt.xpos >> pt.ypos;
	return is;
}

ostream& operator<<(ostream& os, const Point& pt)
{
	os << pt.xpos << "," << pt.ypos << endl;
	return os;
}

int main(void)
{
	Point pt;
	cin >> pt;
	cout << pt;
	return 0;
}