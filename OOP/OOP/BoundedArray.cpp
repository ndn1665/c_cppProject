
#include "BoundedArray.h"
template <typename T>
BoundedArray<T>::BoundedArray(int len) : arrlen(len)
{
	arr = new T[arrlen];
}
template <typename T>
T& BoundedArray<T>::operator[] (int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "index out of range" << endl;
		exit(1);
	}
	return arr[idx];
}
template <typename T>
T BoundedArray<T>::operator[] (int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "index out of range" << endl;
		exit(1);
	}
	return arr[idx];
}
template <typename T>
int BoundedArray<T>::GetArrlen() const
{
	return arrlen;
}
template <typename T>
BoundedArray<T>::~BoundedArray()
{
	delete[]arr;
}