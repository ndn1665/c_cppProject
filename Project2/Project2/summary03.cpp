#include<iostream>

//������
//�����ڴ� ������ ����� ���ÿ� ������ �����ϵ��� �ؾ���
using namespace std;
void swap(int& ref1, int& ref2) { // �������� �Ű����� ����
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}
int main() {

	int num = 3;
	int* ptr = &num;
	int* (&ptr_add) = ptr; // ������ ������ �����ڴ� �̷��� ����

	int num1 = 10;
	int num2 = 20;

	const int n = 10;
	const int& refn = n; //���ȭ�� ���� �����ϴ¹�

	swap(num1, num2);

	int* a = new int; // �ӽð�ü�� �޸� �ּҸ� ����Ŵ
	int& ref = *a; // �ӽð��� ����
	*a = 3;
	cout << ref;

	return 0;
}