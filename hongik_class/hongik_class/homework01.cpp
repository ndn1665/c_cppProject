#include<iostream>
using namespace std;

int main()
{
	int arr[26];

	char text[10001];
	for (int i = 0; i < 26; i++)
	{
		arr[i] = 0;
	}

	cout << "���� �ؽ�Ʈ�� �Է��ϼ���. ������׷��� �׸��ϴ�." << endl;
	cout << "�ؽ�Ʈ�� ���� ; �Դϴ�. 10000������ �����մϴ�." << endl;
	cin.getline(text, 10001, ';');
	int count = 0;
	for (int i = 0; i < strlen(text); i++)
	{
		if (isalpha(text[i]))
		{
			count++;
			text[i] = tolower(text[i]);
			arr[text[i] - 'a']++;
		}
	}

	cout << "�� ���ĺ� �� " << count << endl;
	cout << endl;
	for (int i = 0; i < 26; i++)
	{
		cout << char(i + 97) << " (" << arr[i] << ") " << ": ";
		for (int j = 0; j < arr[i]; j++)
		{
			cout << '*';
		}
		cout << endl;
	}

	return 0;
}