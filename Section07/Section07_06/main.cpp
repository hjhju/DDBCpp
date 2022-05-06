#include <iostream>

using namespace std;

/* Section07_08 매개변수의 기본값 */

void print(int x = 0)
{
	cout << x << endl;
}

// 기본값은 오른쪽순으로 채워져야됨, 아래는 오류뜸
//void print2(int x = 0, int y, int z=30)

void print2(int x, int y = 20, int z = 30); // in header !!

void print2(int x, int y, int z )
{
	cout << x << " "<<y<<" "<<z<<endl;
}

int main()
{
	print(10);
	print(); // defalt값이 설정되어있으면 나옴
	
	print2(100);



	return 0;
}