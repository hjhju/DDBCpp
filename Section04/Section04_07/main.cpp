#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

/* Section04_07 : ������ enumerated types */

enum Color
{
	COLOR_BLACK, // 0
	COLOR_RED,  // 1
	COLOR_BLUE,  // 2
	COLOR_GREEN  // 3
}; // ;��������!!

enum Feeling
{
	HAPPY = -3, // �������� �Ҵ��ϴ� �͵� �����ϱ�� ��
	JOY,
	TIRED = 5,
	BLUE,
};

int main()
{
	Color paint = COLOR_BLACK;
	Color house(COLOR_BLUE);
	Color apple{ COLOR_RED };

	cout << paint << COLOR_BLACK << endl;
	cout << apple << COLOR_RED << endl;

	cout << HAPPY << endl;
	cout << JOY << endl;
	cout << TIRED << endl;
	cout << BLUE << endl;

	int color_id = COLOR_GREEN; // int���� enum�� ���� �� ����
	
	// Color my_color = 3; // enum���� ���� int�� ���� �ִ� ���� �ȵ�
	// ��ȸ�Ͽ� cast�δ� ����
	Color my_color = static_cast<Color>(4);
	cout << my_color << endl;

	// cin >> my_color; // cin���� enum ���� �Ұ�
	// ������ ���� ��ȸ�ؼ��� ����
	int in_num;
	cin >> in_num;

	if (in_num == COLOR_BLACK) my_color = COLOR_BLACK;
	else if (in_num == COLOR_BLUE) my_color = COLOR_BLUE;
	cout << my_color << endl;
	

	// ���ڿ��� �Է¹޴� �͵� ������ but �������� ����
	Color my_color2 = COLOR_GREEN;
	string str_input;
	std::getline(cin, str_input);

	if(str_input=="COLOR_BLACK")
		my_color2 = COLOR_BLACK;
	else if (str_input == "COLOR_BLUE")
		my_color2 = COLOR_BLUE;
	cout << my_color2 << endl;


	return 0;
}