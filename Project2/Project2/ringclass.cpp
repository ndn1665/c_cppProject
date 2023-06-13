#include <iostream>
using namespace std;
class Point
{
private:
	int xpos, ypos;
public:
	Point(int x, int y) :xpos(x), ypos(y) {}
	void ShowPoint() const
	{
		cout << xpos << ',' << ypos << endl;
	}
};

class Circle
{
private:
	Point pt;
	int rad;
public:
	Circle(int x,int y, int r) :pt(x,y), rad(r) {}
	int Getrad() const
	{
		return rad;
	}
	void Showcircle() const
	{
		cout << "point :";
		pt.ShowPoint();
		cout << "center :" << rad << endl;
	}
};
class Ring
{
private:
	Circle cir1;
	Circle cir2;
public:
	Ring(int xpos1, int ypos1, int rad1, int xpos2, int ypos2, int rad2) :cir1(xpos1, ypos1, rad1), cir2(xpos2, ypos2, rad2) {}

	Circle Getinner() const
	{
		if (cir1.Getrad() > cir2.Getrad())
		{
			return cir2;
		}
		else
		{
			return cir1;
		}
	}
	Circle Getoutter() const
	{
		if (cir1.Getrad() > cir2.Getrad())
		{
			return cir1;
		}
		else
		{
			return cir2;
		}
	}
	void Showring() const
	{
		cout << "inner circle info : " << endl;
		Getinner().Showcircle();

		cout << "outter circle info : " << endl;
		Getoutter().Showcircle();
	}
};


int main(void)
{

	Ring ring(1, 1, 4, 2, 2, 9);
	ring.Showring();
	return 0;
}