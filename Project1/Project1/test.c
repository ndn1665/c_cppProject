#include <stdio.h>

int main(void) {

	int a = 4;
	int num;
	const int max = 100; //�̸��� ���� ����� ������ִ� const, �����Ҷ� �ٷ� ���� �־������
	scanf("%d", &num);
	
	double rad;
	scanf("%lf", &rad);

	printf("hello %d",a);
	printf("%f", rad); //double �� �����ʹ� �Է¹��� �� %lf ����Ҷ� %f��

	char a = 'A';
	printf("%d", sizeof(a)); //1 A�� a��� char�� ������ ���� ������ ����� 1�̴�.
	printf("%d", sizeof('A')); //4 ���� ����� ���ڸ� �����Ҷ� ���ڶ��� �ƽ�Ű�ڵ�� ��ȯ�ϸ� �����̹Ƿ� ������ �����Ҷ� int������ �޸𸮿� �����Ѵ�


	do //�ּ� �ѹ��� �����ϴ� while�ݺ���
	{
		int a = 10;
		printf("%d",a);
		a -= 1;
	} while (a >= 9);

	//���׿�����
	//(num1>num2) ? (num1) : (num2); num1>num2�� ���̸� num1��ȯ, �ƴϸ� num2��ȯ

	//static ����
	//static ������ ����� �Լ� �������� ���� ����������, �޸𸮿� ���� ���´�.
	return 0;
}