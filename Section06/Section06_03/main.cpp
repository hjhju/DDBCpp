#include <iostream>
#include <cstring>

using namespace std;

/* Section06_06 c��� ��Ÿ���� �迭 ���ڿ� */

int main()
{
	char myString[] = "string";

	for (int i = 0; i < 7; i++)
	{
		cout << (int)myString[i] << endl; //�ƽ�Ű�ڵ� Ȯ��
	}

	/*
	char myString2[255];
	cin >> myString2;
	myString2[4] = '\0';
	cout << myString2 << endl; //���ڿ��� '\0'�� ������ �������� ���
	*/

	/*
	char myString3[255];
	cin.getline(myString3, 255);
	int idx = 0;
	while (true)
	{
		if (myString3[idx] == '\0') break;
		cout << myString3[idx] << " " << (int)myString3[idx] << endl;
		idx++;
	}
	*/

	char source[] = "Copy this!";
	char dest[50];
	strcpy_s(dest, 50, source);

	cout << source << endl;
	cout << dest << endl;

	if (strcmp(source, dest) == 0) // strcmp�� ������ 0�� ��ȯ
	{
		cout << "same" << endl;
	}
	


	return 0;
}