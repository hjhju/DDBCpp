#include <iostream>

using namespace std;

/* Section04_08 : ���� ���� ������ (������ Ŭ����) */

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
	// ����� ������ ���� ǥ���ؾ���
	Color color = Color::RED;
	Fruit fruit = Fruit::BANANA;

	// enum class�� �Ǹ� �񱳰� �ȵ�
	//if (color == fruit) 
	//	cout << "Color is fruit? " << endl;

	Color color1 = Color::RED;
	Color color2 = Color::BLUE;
	//���� �� ������ �� ����
	if (color1 != color2)
		cout << "Diff " << endl;
	else
		cout << "Same " << endl;

	return 0;
}