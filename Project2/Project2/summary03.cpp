#include<iostream>

//참조자
//참조자는 무조건 선언과 동시에 변수를 참조하도록 해야함
using namespace std;
void swap(int& ref1, int& ref2) { // 참조자의 매개변수 형식
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}
int main() {

	int num = 3;
	int* ptr = &num;
	int* (&ptr_add) = ptr; // 포인터 변수의 참조자는 이렇게 선언

	int num1 = 10;
	int num2 = 20;

	const int n = 10;
	const int& refn = n; //상수화된 변수 참조하는법

	swap(num1, num2);

	int* a = new int; // 임시객체의 메모리 주소를 가리킴
	int& ref = *a; // 임시공간 참조
	*a = 3;
	cout << ref;

	return 0;
}