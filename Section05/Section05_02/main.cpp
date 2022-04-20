#include <iostream>

using namespace std;

/* Section05_03 switch-case */

enum class Colors
{
	BLACK,
	WHITE,
	RED,
	GREEN,
	BLUE
};

void printColorName(Colors color)
{
	//if (color == Colors::BLACK)
	//	cout << "Black" << endl;
	//else if (color == Colors::WHITE)
	//	cout << "White" << endl;
	switch (color)
	{
	case Colors::BLACK:
		cout << "Black"; break;
	case Colors::WHITE:
		cout << "White"; break;
	case Colors::RED:
		cout << "Red"; break;
	// case에서 찾는 값이 없을때 실행됨
	default: 
		cout << "Undefined"; break;
	}
	cout << endl;

	switch (static_cast<int> (color))
	{
	case 0:
		cout << "Black"; break;
	case 1:
		cout << "White"; break;
	case 2:
		cout << "Red"; break;
	default:
		cout << "Undefined"; break;
	}
	cout << endl;


}

int main()
{
	printColorName(Colors::GREEN);

	
	int x = 1; 
	switch (x)
	{
	// 변수 선언까지만 됨!!
	int a; 
	//switch 내부에서는 case이전에는 변수 초기화가 되지 않음
	//int b = 4; 
	case 0:
		a = 2; cout << a; break;
	case 1:
		int b = 4; cout << b; break;
	}

	return 0;
}