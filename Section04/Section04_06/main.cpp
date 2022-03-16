#include <iostream>
#include <string>

using namespace std;

/* Section04_06 : ���ڿ� std string �Ұ� */

int main()
{
	const char my_strs [] = "Hello, World";

	const string my_hello = "Hello, World"; // string�� ����� ���� �ڷ���

	cout << my_hello << endl;


	cout << "Your age? : ";
	string age;
	//cin >> age;
	std::getline(std::cin, age);
	
	// \n�� ������ ���� �ִ� 32767���� ���ڸ� �����϶�� �ǹ�
	// 32767�� ���� �ѹ�
	// std::cin.ignore(32767, '\n');
	// 32767��� �Ʒ��Ͱ��� ǥ�� ����
	// streamsize�� ���� ũ��
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << "Your name? : ";
	string name;
	//cin >> name; // ��ĭ�� �־ �Է��ϸ� ���� ������ ������
	std::getline(std::cin, name); // ���� ĥ������ �Է� ����

	cout << name << " " << age << endl;


	// ���ڿ� ���ϱ� ����
	string a("Hello, ");
	string b("World");
	string hw = a + b;

	hw += "i'm good";

	cout << hw << endl;

	cout << a.length() << endl;


	return 0;
}