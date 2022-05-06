#include <iostream>
#include <string>
#include <cassert> //assert.h
#include <array>

using namespace std;

/* Section07_13 ����� ���α׷��� */
/* Section07_14 �ܾ��ϱ� assert */

void printValue(const array<int, 5> &my_array, const int& ix)
{
	assert(ix >= 0);
	assert(ix <= my_array.size() - 1);

	cout << my_array[ix] << endl;
}


int main()
{
	
	// semantic errors
	int x;
	cin >> x;
	if (x >= 5) // x>5�� �Ǿ�� ��
		cout << "x is greater than 5" << endl;


	// violated assumption
	string hello = "hello, my name is jack jack";
	cout << "input form 0 to " << hello.size() - 1 << endl;
	while (true)
	{
		int ix;
		cin >> ix;
		if (ix >= 0 && ix <= hello.size() - 1)
		{
			cout << hello[ix] << endl;
			break;
		}
		else
			cout << "Please try again" << endl;
	}
	


	// �ܾ��ϱ� assert 
	// ()������ ������ false�� �۵�
	// release ��忡���� �۵����� ����
	const int number = 5;
	assert(number == 5);

	// static_assert�� ������ const�� �پ�� ���� ����
	// ������ �ܰ迡�� ����
	//static_assert(number == 4, "number should be 5"); 

	array<int, 5>my_array{ 1,2,3,4,5 };
	printValue(my_array, 0);




	return 0;
}