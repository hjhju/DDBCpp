#include <iostream>

using namespace std;

/* Section06_17 c++ for-each �ݺ���   */
/* Section06_18 ���̵� ������  */

// void poiner = neneric poiner

int main()
{
	int fibonacci[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

	// change array values
	for (auto& number : fibonacci)
	{
		number *= 10;
	}

	// output
	for (const auto number : fibonacci)
	{
		cout << number << " ";
	}
	cout << endl;

	int max_number = std::numeric_limits<int>::lowest();
	for (const auto &number : fibonacci)
	{
		max_number = std::max(max_number, number);
	}
	cout << max_number << endl;


	int i = 5;
	float f = 3.0;
	char c = 'a';
	void* ptr = nullptr;

	ptr = &i;
	ptr = &f;
	//ptr = &c;

	// ���̵� �����ʹ� ������ ������ �ȵ�
	// cout << ptr + 1 << endl; 
	cout << &f << " " << ptr << endl;

	// � Ÿ������ �𸣱⶧���� de-ref�� �ȵ�
	//cout << *ptr << endl;
	cout << static_cast<float*>(ptr) << endl;




	return 0;
}