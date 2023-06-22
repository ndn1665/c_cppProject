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

	operator++();//전위연산//++pt 이런식으로 사용 가능
	operator++(int); //후위연산, int에 의미는 크게없다. 단지 전위연산과 후위연산을 구분하기 위한것//pt++이렇게 사용 가능,전역함수범위에선 맨
					//마지막에 매개변수로 int 써주면 된다.


	//자료형이 다른 두 객체의 교환법칙이 성립하도록 하는오버로딩
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
// operator*는 pt*times 는 가능하지만 times*pt는 불가능한 코드
//따라서 아래와 같이 위의 코드를 이용하여, 교환법칙이 성립하도록 할 수 있다.

Point operator*(int times, Point& ref)
{
	return ref * times; // ref*times는 ref.operator*(times)호출
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