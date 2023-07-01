//템플릿
#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;

template<class T>
void Swap(T& pt1, T& pt2)
{
	T temp;
	temp = pt1;
	pt1 = pt2;
	pt2 = temp;
}
template<class A>
A SumArray(A arr[], int len)
{
	A sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += arr[i];
	}
	return sum;
}

//템플릿의 특수화
template <class T>
T Max(T a, T b)
{
	return a > b ? a : b;
}
template <> //char*형 템플릿함수가 필요한 경우에는 별도로 만들지 말고 이것을쓰도록 하는 템플릿의 특수화
char* Max(char* a, char* b)
{
	return strlen(a) > strlen(b) ? a : b;
}

template <class B> //클래스 템플릿
class Point
{
private:
	B xpos, ypos;
public:
	Point(B x = 0, B y = 0)
		:xpos(x), ypos(y)
	{}
	void Show() const
	{
		cout << xpos << "," << ypos << endl;
	}
	B Func(B& ref);
};
//template <>를 쓰거나 template <class T>를 쓰는건
// 내용에 T가 포함되어있나 안있나로 정하는 경우가 많다.
//->이건 내가 정리한거임 틀릴 수 있음

template <class B> // 템플릿 클래스의 멤버함수 외부에 정의할때 이렇게 template<class ~ >도 포함해줘야함
B Point<B>::Func(B& ref)
{
	return 0;
}

template<>//템플릿 클래스의 특수화 // 특수화 과정에서 T가 필요하지 않으면 typename T, class T등을 생략해도 됨.
class Point<int>
{
private:
	int xpos, ypos;
public:
	Point<int> (int x, int y)
		: xpos(x + 1), ypos(y + 1)
	{};
	void Show() const
	{
		cout << xpos << "," << ypos << endl;
	}

};
int main(void)
{
	Point<int> pt1(1, 2);//클래스템플릿은 반드시 자료형 정보를 명시해야함
	Point<int> pt2(3, 4);
	Swap(pt1, pt2);
	pt1.Show();
	pt2.Show();
	int arr1[4] = { 1,2,3,4 };
	cout << SumArray(arr1, 4) << endl;
	double arr2[4] = { 1.1, 2.2,3.3,4.1 };
	cout << SumArray(arr2, 4);
	cout << endl;
	return 0;
}