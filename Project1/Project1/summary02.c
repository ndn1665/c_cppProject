#include <stdio.h>

int main(void) {

	int ch1, ch2;//getchar, fgetc의 반환형이 int 이므로 int 로 선언
	ch1 = getchar();//p입력
	ch2 = fgetc(stdin);//엔터 입력

	putchar(ch1);//p출력
	fputc(ch2, stdout);//엔터 출력

	//output:
	//p
	//p


	return 0;
}