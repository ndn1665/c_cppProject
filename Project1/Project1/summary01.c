#include <stdio.h>

int main(void) {

	int a = 4;
	int num;
	const int max = 100; //이름을 지닌 상수로 만들어주는 const, 선언할때 바로 값도 넣어줘야함
	scanf("%d", &num);
	
	double rad;
	scanf("%lf", &rad);

	printf("hello %d",a);
	printf("%f", rad); //double 형 데이터는 입력받을 땐 %lf 출력할땐 %f다

	char a = 'A';
	printf("%d", sizeof(a)); //1 A가 a라는 char형 변수에 담겼기 때문에 사이즈가 1이다.
	printf("%d", sizeof('A')); //4 그저 상수인 문자를 저장할땐 문자또한 아스키코드로 변환하면 정수이므로 정수를 저장할땐 int형으로 메모리에 저장한다

	do //최소 한번은 실행하는 while반복문
	{
		int a = 10;
		printf("%d",a);
		a -= 1;
	} while (a >= 9);

	//삼항연산자
	//(num1>num2) ? (num1) : (num2); num1>num2가 참이면 num1반환, 아니면 num2반환

	//static 변수
	//static 변수는 선언된 함수 내에서만 접근 가능하지만, 메모리에 값이 남는다.

	int onedimarr[4] = { 1,2,3,4 };
	int arr[] = { 1,2,3,4,5,6,7 };
	int arrLen = sizeof(arr) / sizeof(int);

	//int * ptr = 0x0010;
	//ptr +=1 은 0x0014이다 포인터는 증감연산을 하면 자료형의 크기만큼 변화한다.
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
	printf("%d", sizeof(ptr));//8포인터 변수의 크기는 32비트 운영체제인지 64비트 운영체제인지에 따라서 결정된다.
	//따라서 포인터 변수의 크기는 a의 크기와는 상관이 없고,
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
	이렇게 함수에 매개변수로 포인터를 선언했을때, simplefunc에서 arr의 크기를 출력하면 8이 나온다.(str의 크기는 5임에도)
	*/

	const int* ptr = &num; // ptr을 통해서 num의 값을 변경하는 것을 허용하지 않음.
	//num = 40; 이건 가능 ptr을 통해서 num의 값을 변경한것이 아니기 때문
	int* const ptr = &num;//ptr에 저장된 값(num의 주소값)을 변경하는 것을 허용하지 않음.
	//*ptr = 40;이건 가능 ptr의 주소값을 변경한것이 아니기 때문

	int(*ptr)[4]; // int 형 변수를 가리키는 포인터, [4]는 연산시 4칸씩 건너뛰는 포인터를 의미.
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
	void func(int * param, int (*parm)[4] ){} == void func(int param[], int parm[][4] ){} 이것이 가능하다
	그러나 이것이 같은 것은 함수의 매개변수 선언에서만이다. 그 이외의 상황으로 확대해석할 수 없다.

	*/

	return 0;
}