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

	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++) cout << Random::nextInt(1, 100) << ' ';
	cout << endl;
	cout << "알파벳을 랜덤하게 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++) cout << Random::nextAlphabet() << ' ';
	cout << endl;
	cout << "랜덤한 실수를 10개를 출력합니다" << endl;
	for (int i = 0; i < 5; i++) cout << Random::nextDouble() << ' ';
	cout << endl;
	for (int i = 0; i < 5; i++) cout << Random::nextDouble() << ' ';
	cout << endl;
}
