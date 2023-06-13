#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

class Printer
{
private:
	char pstr[100];
public:
	void SetString(const char* s)
	{
		strcpy(pstr, s);
	}
	void ShowString()
	{
		cout << pstr << endl;
	}

};

int main()
{
	Printer pnt;
	pnt.SetString("hello");
	pnt.ShowString();
	return 0;
}