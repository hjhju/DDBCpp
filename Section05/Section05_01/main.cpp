#include <iostream>
#include <cstdlib> // for exit

using namespace std;

/* Section05_01 ���� �帧 ���� control flow */
/* Section05_02 ���ǹ� if  */

// halt
// jump (goto, break, continue)
// conditional branches (if, switch)
// loops (while, do while, for)
// exceptions (try, catch, throw)

int min(int x, int y)
{
	return (x > y ? y : x);
}

int main()
{
	cout << "i love you" << endl;
	// ������ ����!, ����� �Ҷ��� ���� ���
	// exit(0); 

	int x;
	cin >> x;


	if (x > 10)
	{
		cout << "greater than 10" << endl;
	}
	else if(x < 10)
	{
		cout << "less than 10" << endl;
	}
	else 
	{
		return 0; //����
	}


	if (x = 0) //x�� 0�� �ǰ� if(0)�̹Ƿ� ������ �ȵ�
		cout << x << endl;
	cout << x << endl;

	int a, b;
	cin >> a >> b;

	if (a > 0 && b > 0)
	{
		cout << "both are positive" << endl;
	}
	else if (a>0 || b>0)
	{
		cout << "one of the nubmer is positive" << endl;
	}
	else
	{
		cout << "neither number is positive" << endl;
	}


	int c = min(1, 3);
	cout << c << endl;

	return 0;
}