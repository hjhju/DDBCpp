#include <iostream>

using namespace std;

/* Section07_12 재귀적 함수 호출 */


void countDown(int count)
{
	cout << count << endl;
	if(count>0)
		countDown(count - 1);
}

int sumTo(int num)
{
	if (num <= 0)
		return 0;
	else if (num <= 1)
		return 1;
	else
		return sumTo(num - 1) + num;
}


int main()
{
	countDown(5);
	
	cout << sumTo(10) << endl;


	return 0;

}