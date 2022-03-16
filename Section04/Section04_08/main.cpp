#include <iostream>

using namespace std;

/* Section04_08 : 영역 제한 열거형 (열거형 클래스) */

enum class Color
{
	RED, // 0
	BLUE
};

enum class Fruit
{
	BANANA, // 0
	APPLE,
};

int main()
{
	// 선언시 다음과 같이 표기해야함
	Color color = Color::RED;
	Fruit fruit = Fruit::BANANA;

	// enum class가 되면 비교가 안됨
	//if (color == fruit) 
	//	cout << "Color is fruit? " << endl;

	Color color1 = Color::RED;
	Color color2 = Color::BLUE;
	//같은 것 끼리는 비교 가능
	if (color1 != color2)
		cout << "Diff " << endl;
	else
		cout << "Same " << endl;

	return 0;
}