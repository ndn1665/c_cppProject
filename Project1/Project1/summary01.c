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

	int onedimarr[4] = { 1,2,3,4 };
	int arr[] = { 1,2,3,4,5,6,7 };
	int arrLen = sizeof(arr) / sizeof(int);

	//int * ptr = 0x0010;
	//ptr +=1 �� 0x0014�̴� �����ʹ� ���������� �ϸ� �ڷ����� ũ�⸸ŭ ��ȭ�Ѵ�.
	//ex
	/*
	int arr[5] = {1,2,3,4,5};
	int *ptr = arr; or int *ptr = &arr[0];
	
	*ptr = arr[0]
	*(ptr + 1) = arr[1]
	*/

	int a = 10;
	printf("%d", sizeof(a)); //4

	int* ptr = &a;
	printf("%d", sizeof(ptr));//8������ ������ ũ��� 32��Ʈ �ü������ 64��Ʈ �ü�������� ���� �����ȴ�.
	//���� ������ ������ ũ��� a�� ũ��ʹ� ����� ����,
	/*
	void simplefunc(char* arr)
	{
		printf("%d\n", sizeof(arr));
	}

	int main(void) 
	{
		char str[] = "hell";
		simplefunc(str);

		printf("%d", sizeof(str));
		return 0;
	}
	�̷��� �Լ��� �Ű������� �����͸� ����������, simplefunc���� arr�� ũ�⸦ ����ϸ� 8�� ���´�.(str�� ũ��� 5�ӿ���)
	*/

	const int* ptr = &num; // ptr�� ���ؼ� num�� ���� �����ϴ� ���� ������� ����.
	//num = 40; �̰� ���� ptr�� ���ؼ� num�� ���� �����Ѱ��� �ƴϱ� ����
	int* const ptr = &num;//ptr�� ����� ��(num�� �ּҰ�)�� �����ϴ� ���� ������� ����.
	//*ptr = 40;�̰� ���� ptr�� �ּҰ��� �����Ѱ��� �ƴϱ� ����

	int(*ptr)[4]; // int �� ������ ����Ű�� ������, [4]�� ����� 4ĭ�� �ǳʶٴ� �����͸� �ǹ�.
	/*
	int arr[3][2] = {
		{1,2},
		{3,4},
		{5,6}
		}
	int (*ptr)[2] = arr;
	printf("%d",ptr[1][1]);

	*/

	/*
	void func(int * param, int (*parm)[4] ){} == void func(int param[], int parm[][4] ){} �̰��� �����ϴ�
	�׷��� �̰��� ���� ���� �Լ��� �Ű����� ���𿡼����̴�. �� �̿��� ��Ȳ���� Ȯ���ؼ��� �� ����.

	*/

	return 0;
}