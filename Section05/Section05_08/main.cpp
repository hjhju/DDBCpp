#include <iostream>

using namespace std;

/* Section05_10 std::cin �� �߾���  */

int getInt()
{
	while (true)
	{

		cout << "Enter an integer number : ";
		int x;
		cin >> x;
		if (std::cin.fail()) // ������ �ƴ� ���� ��������!!
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n'); // ���� ��ﶧ!! 32767�� ������ ����
			cout << "invalid number, try again" << endl;
		}
		else
		{
			std::cin.ignore(32767, '\n'); // ���� ��ﶧ!! 32767�� ������ ����
			return x;
		}
	}
}

char getOperator()
{
	while (1)
	{
		cout << "Enter an operator (+, -) ";
		char op;
		cin >> op;
		std::cin.ignore(32767, '\n');

		if (op == '+' || op == '-')
			return op;
		else
			cout << "invalid operator, try again" << endl;

	}
	
}

void printResult(int x, char op, int y)
{
	if (op == '+')
		cout << x + y << endl;
	else if (op == '-')
		cout << x - y << endl;

	cout << endl;
}

int main()
{
	int x = getInt();
	char op = getOperator();
	int y = getInt();

	printResult(x, op, y);

	return 0;
}