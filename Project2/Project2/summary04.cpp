#include<iostream>

class Car
{
//protected: 상속관계에서 유도클래스에서의 접근 허용
private://클래스내에서(클래스내에 정의된 함수)접근 허용
	int num;
	const Point pt;
public://어디서든 접근 허용
	Car(int n,int xpos,int ypos)//생성자, 생성자도 함수의 일종이므로 오버로딩이 가능함. 따라서 Car(void) 이런 함수로 생성자를 동시에 만들 수 있음.
		:pt(xpos,ypos) // 멤버 이니셜라이저,Car에 전달된 인자들로 멤버변수의 생성자 호출에 사용.(멤버변수가 객체가 아니어도 가능)
	{					//또한 생성자로는 const멤버변수(또한 참조자 조차)도 초기화 할 수 있다. 
		num = n;
	}
	Car()//생성자를 만들었으므로 객체생성과정에서 인자의 정보를 줘야한다.ex>
		//Car car1(10) or Car car1//두번째껀 인자로 void를 줘서 오버로딩된 Car()을 생성자로 쓰는것.
	{
		num = 0;
	}

	class AAA
	{
	private:
		int num;
		char* name;
	public:	
		AAA(int len) :num(0)
		{
			name = new char[len + 1];
		}
		AAA& CreateInitObj(int n) const
		{
			AAA* ptr = new AAA(n); // 아래에 있는 private생성자로 객체 생성을 가능하게함.(private생성자는 클래스 내부에서만 접근 가능)
			return *ptr;
		}
		AAA& returnthis()
		{
			return *this;//this 포인터는 객체를 가리키고, this 는 객체의 주소값을 담고있다.
		}
		~AAA()
		{
			delete[]name; // 생성자에서 할당한 리소스 삭제는 보통 소멸자에서 해준다
		}
	private:
		AAA(int n) :num(n) {} 
	};


	void shownum() const; // const 함수는 멤버변수의 값을 변경하지 않겠다는 뜻이다.
							// const 함수내에서 다른 함수를 호출할때 호출되는 함수또한 const함수여야한다.(멤버변수의 값을 변경하지 않는 함수여도)
	void shownum2(const Car& easy)
	{
		num = easy.func(); // easy는 const참조자이고 const참조자를 대상으로 값의 변경능력을 가진 함수의 호출을 허용하지 않는다.
							//따라서 const참조자는 const함수만 호출이 가능한 것이다,
	}

};
int main()
{
	AAA base;
	AAA& obj1 = base.CreateInitObj(3);//private 생성자로 생성하는 예//참조자를 반환하므로 참조자로 받도록 코드작성

	delete &obj1; //new AAA(n)을 했기때문에 지워줌
	/*
	delete는 기본적으로 delete ptr처럼 포인터가 참조한 메모리공간을 지워줄때 ptr이 가리키는 주소를 받는다 .(delete 000x01e120이런느낌)
	근데 obj1은 변수처럼 사용되므로 &obj1로 obj1의 주소를 명시하여 delete해줘야한다.
	*/

	return 0;
}