#include <iostream>
#include <bitset>
using namespace std;

/* ch03_09 비트 플래그, 비트 마스크 사용 */

int main()
{
	/*
	bool item1_flag = false;
	bool item2_flag = false;
	bool item3_flag = false;
	bool item4_flag = false;
	*/

	const unsigned char opt0 = 1 << 0;
	const unsigned char opt1 = 1 << 1;
	const unsigned char opt2 = 1 << 2;
	const unsigned char opt3 = 1 << 3;

	cout << bitset<8>(opt0) << endl;
	cout << bitset<8>(opt1) << endl;
	cout << bitset<8>(opt2) << endl;
	cout << bitset<8>(opt3) << endl;

	unsigned char items_flag = 0; // char 타입 즉, 1 byte 하나만 가지고 item 8개를 다룰수 있음
	cout << "no item " << bitset<8>(items_flag) << endl;
	
	// item0 on
	items_flag |= opt0;
	cout << "item0 obtained " << bitset<8>(items_flag) << endl;
	// item3 on
	items_flag |= opt3;
	cout << "item3 obtained " << bitset<8>(items_flag) << endl;
	//item3 off
	items_flag &= ~opt3;
	cout << "item3 lost " << bitset<8>(items_flag) << endl;
	
	//has item1?
	if (items_flag & opt1) { cout << "has item1" << endl; }
	else { cout << "not has item1" << endl; }
	
	//has item0?
	if (items_flag & opt0) { cout << "has item0" << endl; }

	// 아이템 동시에 가질때, obtain 2, 3
	items_flag |= (opt2 | opt3);
	cout << "item2,3 obtained " << bitset<8>(items_flag) << endl;

	if ((items_flag & opt2) && !(items_flag & opt1)) // item2는 있고, item1은 없을때
	{
		//items_flag ^= opt2; // XOR 연산
		//items_flag ^= opt1; // XOR 연산

		items_flag ^= (opt2 | opt1); // 위에 두줄과 동일한 표현
	}
	cout << bitset<8>(items_flag) << endl;

	// 비트 마스크
	const unsigned int red_mask = 0xFF0000;
	const unsigned int green_mask = 0x00FF00;
	const unsigned int blue_mask = 0x0000FF;

	cout << std::bitset<32>(red_mask) << endl;
	cout << std::bitset<32>(green_mask) << endl;
	cout << std::bitset<32>(blue_mask) << endl;

	unsigned int pixel_color = 0xDAA520; // 16진수 DA는 RED A5는 GREEN 20은 BLUE
	cout << std::bitset<32>(pixel_color) << endl;
	
	unsigned char red, green, blue;
	
	blue = (pixel_color & blue_mask);
	green = (pixel_color & green_mask) >> 8;
	red = (pixel_color & red_mask) >> 16;

	cout << "red " << std::bitset<8>(red) << " " << int(red) << endl;
	cout << "green " << std::bitset<8>(green) << " " << int(green) << endl;
	cout <<"blue " << std::bitset<8>(blue) << " " << int(blue) << endl;



	return 0;
}