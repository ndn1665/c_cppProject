#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

enum COMP_POS { CLERK = 1, SENIOR = 2, ASSIST = 3, MANAGER = 4 };

class NameCard
{
private:
	char* name;
	char* compName;
	char* number;
	const int info;
public:
	NameCard(char* inname, char* incomp, char* innum, int ininfo)
		:info(ininfo)
	{
		name = new char[strlen(inname) + 1];
		strcpy(name, inname);
		compName = new char[strlen(incomp) + 1];
		strcpy(compName, incomp);
		number = new char[strlen(innum) + 1];
		strcpy(number, innum);

	}
	void show() const
	{
		cout << "name : " << name << endl;
		cout << "compName : " << compName << endl;
		cout << "number : " << number << endl;
		cout << "information : ";
		switch (info)
		{
		case COMP_POS::CLERK:
			cout << "clerk" << endl;
			break;
		case COMP_POS::SENIOR:
			cout << "senior" << endl;
			break;
		case COMP_POS::ASSIST:
			cout << "assist" << endl;
			break;
		case COMP_POS::MANAGER:
			cout << "manager" << endl;
			break;
		default:
			break;
		}

	}

	~NameCard()
	{
		delete[]name;
		delete[]compName;
		delete[]number;
	}
};


int main()
{
	NameCard manclerk((char*)"lee", (char*)"samsung", (char*)"010-7102-1665", COMP_POS::CLERK);
	manclerk.show();
	cout << endl;
	return 0;
}