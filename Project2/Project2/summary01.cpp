#include<iostream>

using namespace std; //std라는 네임스페이스 안에있는것들은 전부 std를 생략
//using std::cin 만 하면 cin사용할때만 std생략
//namespace abc = aaa::bbb::ccc 이런식으로 특정 네임스페이스 안에 무엇인가에 접근할때 별칭을 사용할 수 있다.


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

//함수 오버로딩
//오버로딩의 기준은 매개변수의 자료형 또는 개수, const 함수 유무
//반환형은 오버로딩의 기준이 될 수 없다.

inline int func(int num) {
	int num2 = num + 1;

	return num2;
}//inline 함수는 함수 실행시 함수의 몸체부분이 함수를 대체하여 코드에 반영하는 것이므로 일반적인 함수처럼 main코드에서 함수로 점프해서 함수를
//사용하는 것이아닌, 전처리 과정에서 인라인함수의 몸체부분이 그냥 main코드 자체에 삽입되는 것이다.

int main(void)
{
	int num2 = 10;
	int num3 = 30;
	swap(&num2, &num3);

	return 0;
}