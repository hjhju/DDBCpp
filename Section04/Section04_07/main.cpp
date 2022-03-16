#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

/* Section04_07 : 열거형 enumerated types */

enum Color
{
	COLOR_BLACK, // 0
	COLOR_RED,  // 1
	COLOR_BLUE,  // 2
	COLOR_GREEN  // 3
}; // ;잊지말것!!

enum Feeling
{
	HAPPY = -3, // 수동으로 할당하는 것도 가능하기는 함
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

	int color_id = COLOR_GREEN; // int형에 enum형 넣을 수 있음
	
	// Color my_color = 3; // enum형에 직접 int형 변수 넣는 것은 안됨
	// 우회하여 cast로는 가능
	Color my_color = static_cast<Color>(4);
	cout << my_color << endl;

	// cin >> my_color; // cin으로 enum 정의 불가
	// 다음과 같이 우회해서는 가능
	int in_num;
	cin >> in_num;

	if (in_num == COLOR_BLACK) my_color = COLOR_BLACK;
	else if (in_num == COLOR_BLUE) my_color = COLOR_BLUE;
	cout << my_color << endl;
	

	// 문자열로 입력받는 것도 가능함 but 권장하지 않음
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