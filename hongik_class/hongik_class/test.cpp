#include<iostream>
#include<cstdlib>
#include<ctime>
#pragma warning(disable:4996);
using namespace std;

class Random
{
private:
	static int num;
public:
	Random() 
	{}

	static void seed()
	{
		srand((unsigned int)time(NULL));
	}

	static int nextInt(int low, int high)
	{

		return ((rand() % (high - low + 1)) + low); 
	}

	static char nextAlphabet()
	{
		if (rand() % 2 == 0) {
			return 'A' + (rand() % 26);
		}
		else {
			return 'a' + (rand() % 26);
		}
	}
	static double nextDouble()
	{
		return (double)1 / nextInt(1,RAND_MAX);
	}

};

int main() {
	Random::seed();

	cout << "1���� 100���� ������ ���� 10���� ����մϴ�" << endl;
	for (int i = 0; i < 10; i++) cout << Random::nextInt(1, 100) << ' ';
	cout << endl;
	cout << "���ĺ��� �����ϰ� 10���� ����մϴ�" << endl;
	for (int i = 0; i < 10; i++) cout << Random::nextAlphabet() << ' ';
	cout << endl;
	cout << "������ �Ǽ��� 10���� ����մϴ�" << endl;
	for (int i = 0; i < 5; i++) cout << Random::nextDouble() << ' ';
	cout << endl;
	for (int i = 0; i < 5; i++) cout << Random::nextDouble() << ' ';
	cout << endl;
}
