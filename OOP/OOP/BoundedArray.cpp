#include "BankingCommonDecl.h"
#include "BoundedArray.h"

BoundedArray::BoundedArray(int len) : arrlen(len)
{
	arr = new AccountPtr[arrlen];
}

AccountPtr& BoundedArray::operator[] (int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "index out of range" << endl;
		exit(1);
	}
	return arr[idx];
}
AccountPtr BoundedArray::operator[] (int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "index out of range" << endl;
		exit(1);
	}
	return arr[idx];
}
int BoundedArray::GetArrlen() const
{
	return arrlen;
}
BoundedArray::~BoundedArray()
{
	delete[]arr;
}