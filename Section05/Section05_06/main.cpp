#include <iostream>

using namespace std;

/* Section05_08 break, continue */
void breakOrReturn()
{
	while (true)
	{
		char ch;
		cin >> ch;

		if (ch == 'b')
			break;
		if (ch == 'r')
			return;
	}
	cout << "Hello" << endl;
}

int main()
{
	int count = 0;
	while (true)
	{
		cout << count << endl;
		if (count == 10) break;
		count++;
	}

	// breakOrReturn();

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)continue; //�ǳʶٶ�� �ǹ�
		cout << i << endl;
	}
	
	int count2(0);

	do
	{
		if (count2 == 5)
			continue;
		cout << count2 << endl;

		// count2++ �� ���ο� �ִٸ� continue������ ���� ���� �ɸ�!!!
		// count2++;

	} while (++count2 < 10);

	
	count = 0;

	bool flag = false;
	while (!flag)
	{
		char ch;
		cin >> ch;

		cout << ch << " " << count++ << endl;
		
		if (ch == 'x')
			flag = true;
	}



	return 0;
}