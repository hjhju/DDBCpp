#include <iostream>

using namespace std;

/* ch03_06 �� ������*/

int main()
{
	// logical NOT
	bool x = true;
	cout << !x << endl;

	// logical AND
	bool y = false;
	cout << (x && y) << endl; // ������ �켱���������� �����ߴ°�

	bool hit = true;
	int health = 10;

	if (hit == true && health < 20)
	{
		cout << "die" << endl;
	}
	else
		health -= 20;

	int a = 5;
	int b = 7;

	if (!a == b) // ������ �켱���������� (!a)==b �� �� 
	{
		cout << " a does not equal b" << endl;
	}
	else
		cout << " a equals b" << endl;

	int v = 1;
	if (v == 0 || v == 1)
		cout << "v is 0 or 1" << endl;

	// short circuit evaluation
	int c = 1;
	int d = 2;

	if (c == 1 && d++ == 2) // c�� 1�̾ƴϸ�, �� ���� false�� �Ǹ� �ڴ� ������ �ȵǹǷ� d�� �״�� 2
	{
		//do something
	}

	cout << d << endl;

	// de morgan's law
	// !(x && y) = !x || !y

	// XOR
	if (x != y)
	{

	}




	return 0;
}