#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Section17_04 ���� �����ϱ�� �迭���� ��ȯ */

int main()
{
	string my_str("abcdefg");
	cout << my_str[0] << endl;
	cout << my_str[3] << endl;
	my_str[3] = 'X';
	cout << my_str << endl;

	// ��Ÿ�� ���� �߻�
	try
	{
		// ����ó���� ������ �������� �Ʒ��� ��Ÿ�� ���� �߻�
		//my_str[100] = 'Z';

		my_str.at(100) = 'Z';
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	string my_str2("abcdefg");
	cout << my_str2.c_str() << endl;
	cout << my_str.c_str()[6] << endl;

	const char* arr = my_str2.c_str();  
	cout << (int)arr[6] << endl;
	cout << (int)arr[7] << endl; // c��Ÿ�� ���ڿ��� ��ó�� �ڿ� �� ���ڸ� �־��ֹǷ� 0�� ����

	char buf[20];
	my_str2.copy(buf, 5, 0); // ����� ������ �� ���ڴ� �ڵ����� �־��������� -> �����Ⱚ ��µ�
	buf[5] = '\0';
	cout << buf << endl;



	return 0;
}