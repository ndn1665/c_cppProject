#include <stdio.h>


//구조체
typedef struct point //point 생략 가능
{
	int xpos;
	int ypos;
}Point;
/*
struct point
{
	int xpos;
	int ypos;
};
typedef struct point Point;
이것과 같은 말이다.
*/

struct circle
{
	double radius;
	const struct point* pptr;
};

int main(void) {
	struct point pos1 = { 1,2 };
	Point pos2 = { 3,4 };
	struct point* pptr1 = &pos1;
	struct point* pptr2 = &pos2;


	pptr1->xpos = 5;
	pptr1->ypos = 6;

	struct circle cir1 = { 3.14,&pos1 };

	printf("%d %d \n", pos1.xpos, pos1.ypos);
	printf("%d %d \n", pptr1->xpos, pptr1->ypos);
	printf("%d %d \n", pptr2->xpos, pptr2->ypos);
	printf("%g %d %d\n", cir1.radius, cir1.pptr->xpos, cir1.pptr->ypos);
	printf("%p %p\n", &pos1, &pos1.xpos); //구조체 변수의 주소값은 구조체 변수의 첫번째 멤버의 주소값과 같다.
	return 0;
}