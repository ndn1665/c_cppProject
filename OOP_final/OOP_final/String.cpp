#include "BankingCommonDecl.h"

class String
{
private:
	int len;
	char* str;
public:
	String(){}
	String(const char* s)
	{
		len = strlen(s) + 1;
		str = new char[len];
		strcpy(str, s);
	}
};