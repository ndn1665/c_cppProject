#include<iostream>

using namespace std;

typedef struct {
	int xpos;
	int ypos;
}Point;

Point pntAdder(const Point& cp1, const Point& cp2);

int main(void)
{
	Point *p1 = new Point;
	Point *p2 = new Point;
	
	*p1 = { 1,2 };
	*p2 = { 3,4 };

	

	Point answer = pntAdder(*p1, *p2);

	cout << answer.xpos << endl;
	cout << answer.ypos << endl;


	return 0;
}

Point pntAdder(const Point& cp1, const Point& cp2) {
	Point* result = new Point;
	result->xpos = cp1.xpos + cp2.xpos;
	result->ypos = cp1.ypos + cp2.ypos;
	return *result;

}