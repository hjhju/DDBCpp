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
		if (i % 2 == 0)continue; //건너뛰라는 의미
		cout << i << endl;
	}
	
	int count2(0);

	do
	{
		if (count2 == 5)
			continue;
		cout << count2 << endl;

		// count2++ 가 내부에 있다면 continue때문에 무한 루프 걸림!!!
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