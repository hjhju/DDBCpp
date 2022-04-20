#include <iostream>

using namespace std;

/* Section05_10 std::cin 더 잘쓰기  */

int getInt()
{
	while (true)
	{

		cout << "Enter an integer number : ";
		int x;
		cin >> x;
		if (std::cin.fail()) // 정수가 아닌 값이 들어왔을때!!
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n'); // 버퍼 비울때!! 32767은 적당한 숫자
			cout << "invalid number, try again" << endl;
		}
		else
		{
			std::cin.ignore(32767, '\n'); // 버퍼 비울때!! 32767은 적당한 숫자
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