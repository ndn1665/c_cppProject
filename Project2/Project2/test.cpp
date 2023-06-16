#include<iostream>
#pragma warnings(disable: 4996)

using namespace std;
using std::cin;

class Simple
{
private:
	int num;
	char name[20];
public:
	Simple(int n, char* inname)
		:num(n) 
	{}
	void check(Simple& other)
	{
		cout << other.num << endl;
	}
};


int main(void)
{
	Simple one(3);
	Simple two(5);
	one.check(two);
	two.check(one);
	return 0;
}