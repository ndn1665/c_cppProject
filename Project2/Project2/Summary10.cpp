//���ø�
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

//���ø��� Ư��ȭ
template <class T>
T Max(T a, T b)
{
	return a > b ? a : b;
}
template <> //char*�� ���ø��Լ��� �ʿ��� ��쿡�� ������ ������ ���� �̰��������� �ϴ� ���ø��� Ư��ȭ
char* Max(char* a, char* b)
{
	return strlen(a) > strlen(b) ? a : b;
}

template <class B> //Ŭ���� ���ø�
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
//template <>�� ���ų� template <class T>�� ���°�
// ���뿡 T�� ���ԵǾ��ֳ� ���ֳ��� ���ϴ� ��찡 ����.
//->�̰� ���� �����Ѱ��� Ʋ�� �� ����

template <class B> // ���ø� Ŭ������ ����Լ� �ܺο� �����Ҷ� �̷��� template<class ~ >�� �����������
B Point<B>::Func(B& ref)
{
	return 0;
}

template<>//���ø� Ŭ������ Ư��ȭ // Ư��ȭ �������� T�� �ʿ����� ������ typename T, class T���� �����ص� ��.
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
	Point<int> pt1(1, 2);//Ŭ�������ø��� �ݵ�� �ڷ��� ������ ����ؾ���
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