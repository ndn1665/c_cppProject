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
	//singer.size(); -> ���̱��ϴ� �Լ� .size()
	
	return 0;
}