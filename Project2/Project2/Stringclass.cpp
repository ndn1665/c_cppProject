
/*
#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;

char* test()
{
	char a[100] =  "test";
	return a;
}

int main(void)
{
	cout<<test();
	cout << endl;
	return 0;
}
*/

#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;

class String
{
private:
	int arrlen;
	char* str;
public:
	String()
	{
		arrlen = 0;
		str = NULL;
	}
	String(const char* s)
	{
		arrlen = strlen(s) + 1;
		str = new char[arrlen];
		strcpy(str, s);
	}
	String(const String& s)
	{
		arrlen = s.arrlen;
		str = new char[arrlen];
		strcpy(str, s.str);
	}
	~String()
	{
		if (str != NULL)
		{
			delete[]str;
		}
	}

	String& operator=(const String& s)
	{
		arrlen = s.arrlen;
		str = new char[arrlen];
		strcpy(str, s.str);
		return *this;
	}

	String operator+(String& s)// ��ȯ���� String& ���� �ϸ� �ȵǴ� ����
		//��ȯ���� String���� �ؾ� �ӽð�ü�� �����ؼ� ������ �� �ֵ��� �ϴ°ǵ�
		//��ȯ���� String&���� �ϸ� �Լ� ���ο� �ִ� ��ü�� ������(�ӽð�ü�� ��ȯ�ϸ鼭 �����ؼ� �����ϴ°��� �ƴ�)
	{
		char* temp;
		temp = new char[arrlen + s.arrlen - 1];
		strcpy(temp, str);
		strcat(temp, s.str);
		String temps = temp;
		delete[]temp;
		return temps;
	}
	String& operator+=(String& s)
	{
		*this = *this + s;
		return *this;
	}
	friend ostream& operator<<(ostream& os, String& s);
};
ostream& operator<<(ostream& os, String& s)
{
	os << s.str << endl;
	return os;
}
istream& operator>>(istream& is, String& s)
{
	char tmp[100];
	is >> tmp;
	s = tmp;
	return is;
}
int main(void)
{
	String str1 = "hello";
	String str2 = "hi";
	String str3;
	str3 = str1 + str2;
	String str4;
	cin >> str4;
	str4 += str1;
	cout << str1;
	cout << str2;
	cout << str3;
	cout << str4;
	cout << endl;
	return 0;
}