#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;

class BoundedArray
{
private:
	int * arr;
	int ylen;
public:
	BoundedArray(int len =0)
		:ylen(len)
	{
		arr = new int[len];
	}
};

class Bounded2Darray :public BoundedArray
{
private:
	int xlen;
public:
	Bounded2Darray(int x,int y)
		:xlen(x),BoundedArray(y)
	{}

};

int main(void)
{
	Bounded2Darray array(3, 4);
	cout<< array[0][0];
	cout << endl;
	return 0;
}