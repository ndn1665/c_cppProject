#ifndef __BOUNDED_ARRAY_H__
#define __BOUNDED_ARRAY_H__
#include "BankingCommonDecl.h" // erase later
#include "Account.h"

typedef Account * AccountPtr;

class BoundedArray
{
private:
	AccountPtr * arr;
	int arrlen;
public:
	BoundedArray(int len = 100);
	AccountPtr& operator[] (int idx);
	AccountPtr operator[] (int idx) const;
	int GetArrlen() const;
	~BoundedArray();
};

#endif // !__BOUNDED_ARRAY_H__
