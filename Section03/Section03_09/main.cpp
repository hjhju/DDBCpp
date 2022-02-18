#include <iostream>
#include <bitset>
using namespace std;

/* ch03_09 ��Ʈ �÷���, ��Ʈ ����ũ ��� */

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

	unsigned char items_flag = 0; // char Ÿ�� ��, 1 byte �ϳ��� ������ item 8���� �ٷ�� ����
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

	// ������ ���ÿ� ������, obtain 2, 3
	items_flag |= (opt2 | opt3);
	cout << "item2,3 obtained " << bitset<8>(items_flag) << endl;

	if ((items_flag & opt2) && !(items_flag & opt1)) // item2�� �ְ�, item1�� ������
	{
		//items_flag ^= opt2; // XOR ����
		//items_flag ^= opt1; // XOR ����

		items_flag ^= (opt2 | opt1); // ���� ���ٰ� ������ ǥ��
	}
	cout << bitset<8>(items_flag) << endl;

	// ��Ʈ ����ũ
	const unsigned int red_mask = 0xFF0000;
	const unsigned int green_mask = 0x00FF00;
	const unsigned int blue_mask = 0x0000FF;

	cout << std::bitset<32>(red_mask) << endl;
	cout << std::bitset<32>(green_mask) << endl;
	cout << std::bitset<32>(blue_mask) << endl;

	unsigned int pixel_color = 0xDAA520; // 16���� DA�� RED A5�� GREEN 20�� BLUE
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