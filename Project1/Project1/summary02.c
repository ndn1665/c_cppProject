#include <stdio.h>

int main(void) {

	int ch1, ch2;//getchar, fgetc�� ��ȯ���� int �̹Ƿ� int �� ����
	ch1 = getchar();//p�Է�
	ch2 = fgetc(stdin);//���� �Է�

	putchar(ch1);//p���
	fputc(ch2, stdout);//���� ���

	//output:
	//p
	//p


	return 0;
}