#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;

class Simple
{
private:
	int num;
	friend class diffclass;// diffclass�� SImple class�� private������ ���� �����ϴ�. //�̷��� friend ������ private�̳� public ���� �ƹ� ������ �����ϸ� �ȴ�.
	friend void SimpleFunc();//�̷��� �Լ��� friend���� �����ϴ�.������ �Ǵ°��̹Ƿ� �ܺο� ������ �Լ������� ���� �ʾƵ� �ȴ�.
	static int simcount1;// static �������, ��ü ���ο� ���������� �ʰ� ��ü �ܺο��� ��ü�鰣�� ������ �� �ֵ��� ����.��ġ �������ó�� ���� ����
						//������ ��������� �ƴ�
public:
	static int simcount2;//�̷��� static������ public�� ����Ǹ� ��𼭵��� ���� ������ ������ �ȴ�.
						//main���� cout<<SImple::simcount2 �̷������� ���� �����ϴ�.(Simple.simcount2 �̷��Դ� �Ұ���)
	
	static void show() // static ����Լ��� static�������,����Լ�����!! ������ �� �ִ�. �Ϲ� �������,����Լ����� ������ �� ����.
	{
		simcount1 += 1; 
	}
	Simple(int n)
		:num(n)
	{}
	Simple(Simple& copy)
		/*
		���������, ����������� �Ű������� �����ڷ� �޴� ������ simple A=  B ��� ȣ���� ������,
		���� ����������� �Ű������� SImple copy���, A(B)��� ������ copy�� B��� ���� ���޵ǰ� call-by-value�� �ٸ����δ� call-by-copy�̹Ƿ�
		copy = B��� ���°� �ȴ�.���� copy(B)�� �ǰ�, copy(B)�� �ǹǷ� ���ؼ� copy�� ��������ڰ� �� ȣ��Ǿ� copy�� ����������� �Ű������� copy�� 
		�� B�� �����ϴ� ������ ��������ڰ� �� ȣ��Ǵ� ������Ͱ� �Ͼ�� �ȴ�.
		*/
	{
	}
};
int Simple::simcount = 0; //static ������ �̷��� class�ܺο��� �ʱ�ȭ �ؾ� �Ѵ�.

int main(void)
{
	Simple(100); // <-> Simple simp(100);
	//�̹���� �ӽð�ü�� �����ϴ� �������, �ӽð�ü�� ���� ������ �Ѿ�� �Ҹ������, �����ڰ� �ӽð�ü�� �����Ͽ������� �ٷμҸ������ �ʴ´�.
	
	cout << endl;
	return 0;
}