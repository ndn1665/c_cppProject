#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;

class Myfriend
{
private:
	char* name;
	int age;
public:
	Myfriend(char* inname, int inage)
		:age(inage)
	{
		name = new char[strlen(inname) + 1];
		strcpy(name, inname);
	}

	void ShowFriendInfo()
	{
		cout << "my name is " << name << endl;
		cout << "im " << age << endl;
	}

	~Myfriend()
	{
		delete[]name;
	}
};

class MyfriendDetail : public Myfriend
{
private:
	char* addr;
	char* phone;
public:
	MyfriendDetail(char* inname, int inage, char* inaddr, char* inphone)
		:Myfriend(inname, inage)
	{
		addr = new char[strlen(inaddr) + 1];
		strcpy(addr, inaddr);
		phone = new char[strlen(inphone) + 1];
		strcpy(phone, inphone);
	}

	void ShowFriendDetailInfo()
	{
		ShowFriendInfo();
		cout << "my address is " << addr << endl;
		cout << "my phone number is " << phone << endl;
	}
	~MyfriendDetail()
	{
		delete[]addr;
		delete[]phone;
	}
};

int main(void)
{
	MyfriendDetail gfriend((char*)"baejihee", 23, (char*)"½ÃÈ«šÃ", (char*)"01058309247");
	gfriend.ShowFriendDetailInfo();
	cout << endl;
	return 0;
}