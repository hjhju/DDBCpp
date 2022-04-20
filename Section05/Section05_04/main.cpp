#include <iostream>

using namespace std;

/* Section05_05 �ݺ��� while */
/* Section05_06 �ݺ��� do-while */

int main()
{
	// while
	cout << "while-loop test" << endl;

	int count = 0;

	while (count<10)
	{
		cout << count++ << endl;
	}

	while (1)
	{
		// while ���ο��� count������ �����ؼ� ���� �ʹٸ� static�� �ٿ��� ��
		static int count2 = 0;
		cout << count2++ << endl;

		if (count2 == 10) break;
	}

	// �Ʒ� ������ overflow ����
	/*
	unsigned int count3 = 10;
	while (count3 >=0)
	{
		if (count3 == 0) cout << "zero";
		else cout << count3 << " ";
		
		count3--;
	}
	*/

	count = 1;
	while (count < 100)
	{
		if (count % 5==0)
			cout << "hello " << count << endl;
		count++;
	}

	int outer = 1;
	while (outer <= 5)
	{
		int inner = 1;
		while (inner <= outer)
		{
			cout << inner << " ";
			inner++;
		}
		cout << endl;
		outer++;
	}

	cout << endl;

	outer = 5;
	while (outer >= 1)
	{
		int inner = 1;
		while (inner <= outer)
		{
			cout << inner << " ";
			inner++;
		}
		cout << endl;
		outer--;
	}

	// do-while
	cout << "do-while-loop test" << endl;
	
	int selection;
	do
	{
		cout << "1. add " << endl;
		cout << "2. sub" << endl;
		cout << "3. mult" << endl;
		cout << "4. div" << endl;
		cin >> selection;
	} while (selection <= 0 || selection >= 5);
	cout << "You selected " << selection << endl;

	return 0;
}