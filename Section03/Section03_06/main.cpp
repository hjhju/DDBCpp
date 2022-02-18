#include <iostream>

using namespace std;

/* ch03_06 논리 연산자*/

int main()
{
	// logical NOT
	bool x = true;
	cout << !x << endl;

	// logical AND
	bool y = false;
	cout << (x && y) << endl; // 연산자 우선순위때문에 오류뜨는것

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

	if (!a == b) // 연산자 우선순위때문에 (!a)==b 가 됨 
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

	if (c == 1 && d++ == 2) // c가 1이아니면, 즉 앞이 false가 되면 뒤는 연산이 안되므로 d는 그대로 2
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