#include<iostream>
#include<string>
using namespace std;

int main()
{
	char line[100];
	int len = 50;
	cin.getline(line, len, '\n');// line�� len-1��ŭ �����Է�, \n�� ������ (len-1��ŭ �Է� ���ߴ���) ���� // �̰� ���ڿ� �迭�� ����°��̴�.
	//len �ڸ��� �ι��ڰ� ���ԵǱ⿡ �� len -1������ �Է� �ȴ�. �׸��� string line���� ����� �� ����. char line�̾�� �Ѵ�. // istream ����� ���Ե� �Լ�
	
	string line2; //string�� ���ڿ� ũ�⿡ ������ ����
	getline(cin, line2);//getline(cin,����,������(��������'\n'))  // string ����� ���Ե� �Լ�
	string elvis("elvis presly");
	cout << elvis[0] << endl; // e
	string singer;
	if (singer == elvis) {}//�̷������� ��� ����
	singer.size(); //-> ���̱��ϴ� �Լ� .size() or singer.length() or singer.capacity() -> 

	/*
	�߰����� string�Լ�
	singer.append() == singer+"sentence"
	singer.substr(������ġ,ũ��)
	singer.replace(������ġ,ũ��, �ٲ�string)
	singer.find(���ڿ�,start_index,����)

	���ڿ� ������
	+,+=, ==, < ���

	�����Լ�
	stoi
	to_string
	*/

	string str("hello");
	string copystr(str);

	char text[] = { 'l','o','v','e','\0' };
	string love(text);

	cout << str << endl;
	cout << copystr << endl;
	cout << love << endl;

	
	return 0;
}