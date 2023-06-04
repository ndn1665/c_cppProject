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
	//static 변수가 선언된 함수 내에서만 접근 가능하지만, 메모리에 값이 남는다.
	return 0;
}