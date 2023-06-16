#include<iostream>

void default_parameter(int num1, int num2 = 8);
//매개변수에 아무런 값을 안넣으면 매개변수 num에 8대입
//매개변수의 디폴트 값은 이렇듯 함수의 선언부분에서 설정해줘야한다.
//매개변수의 디폴트 값은 오른쪽부터 설정해줘야하고 왼쪽이 설정돼있고 오른쪽이 비어있는 형태는 불가능하다. 
void swap(int* ptr1, int* ptr2) {
	int temp;
	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

void swap(char* ptr1, char* ptr2) {
	char temp;
	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
//swap함수 오버로딩
//오버로딩의 기준은 매개변수의 자료형 또는 개수
//반환형은 오버로딩의 기준이 될 수 없다.
//함수의 const선언 유무도 함수 오버로딩의 조건이 된다.

inline int func(int num) {
	int num2 = num + 1;

	return num2;
}//inline 함수는 함수 실행시 함수의 몸체부분이 함수를 대체하여 코드에 반영하는 것이므로 일반적인 함수처럼 main코드에서 함수로 점프해서 함수를
//사용하는 것이아닌, 전처리 과정에서 인라인함수의 몸체부분이 그냥 main코드 자체에 삽입되는 것이다.

int main(void)
{
	int num1 = 20;
	int num2, num3;
	char ch1, ch2;

	std::cout << "hello world" << num1 << std::endl;
	std::cin >> num2 >> num3;
	std::cout << num2 + num3 << std::endl;
	std::cin >> ch1 >> ch2;
	swap(&num2, &num3);
	swap(&ch1, &ch2);

	std::cout << num2 << num3;
	std::cout << ch1 << ch2;



	return 0;
}