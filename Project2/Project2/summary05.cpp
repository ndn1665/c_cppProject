#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;

class Simple
{
private:
	int num;
	friend class diffclass;// diffclass는 SImple class의 private영역에 접근 가능하다. //이러한 friend 선언은 private이나 public 둘중 아무 영역에 선언하면 된다.
	friend void SimpleFunc();//이렇게 함수의 friend선언도 가능하다.선언이 되는것이므로 외부에 별도의 함수선언을 하지 않아도 된다.
	static int simcount1;// static 멤버변수, 객체 내부에 존재하지는 않고 객체 외부에서 객체들간에 공유할 수 있도록 존재.마치 멤버변수처럼 접근 가능
						//하지만 멤버변수는 아님
public:
	static int simcount2;//이렇게 static변수가 public에 선언되면 어디서든지 접근 가능한 변수가 된다.
						//main에서 cout<<SImple::simcount2 이런식으로 접근 가능하다.(Simple.simcount2 이렇게는 불가능)
	
	static void show() // static 멤버함수는 static멤버변수,멤버함수에만!! 접근할 수 있다. 일반 멤버변수,멤버함수에는 접근할 수 없다.
	{
		simcount1 += 1; 
	}
	Simple(int n)
		:num(n)
	{}
	Simple(Simple& copy)
		/*
		복사생성자, 복사생성자의 매개변수를 참조자로 받는 이유는 simple A=  B 라고 호출을 했을때,
		만약 복사생성자의 매개변수가 SImple copy라면, A(B)라고 했을때 copy에 B라는 값이 전달되고 call-by-value는 다른말로는 call-by-copy이므로
		copy = B라는 형태가 된다.따라서 copy(B)가 되고, copy(B)가 되므로 인해서 copy의 복사생성자가 또 호출되어 copy의 복사생성자의 매개변수인 copy가 
		또 B를 복사하는 과정에 복사생성자가 또 호출되는 무한재귀가 일어나게 된다.
		*/
	{
	}
};
int Simple::simcount = 0; //static 변수는 이렇듯 class외부에서 초기화 해야 한다.

int main(void)
{
	Simple(100); // <-> Simple simp(100);
	//이방식은 임시객체를 생성하는 방식으로, 임시객체는 다음 행으로 넘어가면 소멸되지만, 참조자가 임시객체를 참조하였을때는 바로소멸되지는 않는다.
	
	cout << endl;
	return 0;
}