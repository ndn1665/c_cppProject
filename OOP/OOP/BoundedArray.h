#ifndef __BOUNDED_ARRAY_H__
#define __BOUNDED_ARRAY_H__
#include "BankingCommonDecl.h" // erase later
#include "Account.h"

template <typename T>
class BoundedArray
{
private:
	T * arr;
	int arrlen;
public:
	BoundedArray(int len = 100);
	T& operator[] (int idx);
	T operator[] (int idx) const;
	int GetArrlen() const;
	~BoundedArray();
};

#endif // !__BOUNDED_ARRAY_H__
