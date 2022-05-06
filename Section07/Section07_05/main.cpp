#include <iostream>

using namespace std;

/* Section07_07 함수 오버로딩  */

// 함수 오버로딩
//   - 동일한 이름을 가진 함수를 여러개 만드는 것
//   - 리턴타입이 달라도, 파라미터가 같으면 안됨!!

int add(int x, int y)
{
	return x + y;
}

double add(double x, double y)
{
	return x + y;
}

void getRandom(int &x){}
void getRandom(double& x) {}

// 아래의 것은 같은 타입으로 인식됨!!
//typedef int my_int;
//void print(int x) {}
//void print(my_int x) {}

void print(char* value) {}
void print(unsigned int value) {}
void print(float value) {}


int main() 
{
	cout << add(1, 2) << endl;
	cout << add(3.0, 4.0) << endl;

	print(0u);
	print((unsigned int)'a');
	print(3.14f);

	return 0;
}