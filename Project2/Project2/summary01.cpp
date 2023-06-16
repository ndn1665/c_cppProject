#include<iostream>

void default_parameter(int num1, int num2 = 8);
//�Ű������� �ƹ��� ���� �ȳ����� �Ű����� num�� 8����
//�Ű������� ����Ʈ ���� �̷��� �Լ��� ����κп��� ����������Ѵ�.
//�Ű������� ����Ʈ ���� �����ʺ��� ����������ϰ� ������ �������ְ� �������� ����ִ� ���´� �Ұ����ϴ�. 
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
//swap�Լ� �����ε�
//�����ε��� ������ �Ű������� �ڷ��� �Ǵ� ����
//��ȯ���� �����ε��� ������ �� �� ����.
//�Լ��� const���� ������ �Լ� �����ε��� ������ �ȴ�.

inline int func(int num) {
	int num2 = num + 1;

	return num2;
}//inline �Լ��� �Լ� ����� �Լ��� ��ü�κ��� �Լ��� ��ü�Ͽ� �ڵ忡 �ݿ��ϴ� ���̹Ƿ� �Ϲ����� �Լ�ó�� main�ڵ忡�� �Լ��� �����ؼ� �Լ���
//����ϴ� ���̾ƴ�, ��ó�� �������� �ζ����Լ��� ��ü�κ��� �׳� main�ڵ� ��ü�� ���ԵǴ� ���̴�.

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