/*
���Ǻ� ������

#include<stdio.h>
#define ADD 1
#define MIN 0

int main(void) {
	int num1 = 1, num2 = 2;

#if ADD // ADD�� ���̸� endif ���̿� �ִ� �ڵ� ����
	printf("%d", num1 + num2);
#elif
	//�ڵ�
#else
	//�ڵ�
#endif

#ifdef MIN //MIN �� ���� �Ǿ� �ִٸ� ���� �ڵ� ����
	printf("%d",num1 - num2);
#endif

	return 0;
}

*/