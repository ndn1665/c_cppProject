/*
조건부 컴파일

#include<stdio.h>
#define ADD 1
#define MIN 0

int main(void) {
	int num1 = 1, num2 = 2;

#if ADD // ADD가 참이면 endif 사이에 있는 코드 실행
	printf("%d", num1 + num2);
#elif
	//코드
#else
	//코드
#endif

#ifdef MIN //MIN 이 정의 되어 있다면 사이 코드 실행
	printf("%d",num1 - num2);
#endif

	return 0;
}

*/
/*
헤더파일의 중복삽입 문제해결법
#ifndef __STDIV2_H__
#define __STDIV2_H__
typedef struct div{
	int quotient;
	int remainder;
}
#endif
*/

