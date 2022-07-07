#include "Storage.h"

/* Section 13_04 함수 템플릿 특수화 */

template <typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

// 특수한 타입에 대해서 아래를 빌드하도록 함
template <>
char getMax(char x, char y)
{
	std::cout << "warning : comparing chars" << std::endl;
	return (x > y) ? x : y;
}

int main()
{
	std::cout << getMax(1,2) << std::endl;
	std::cout << getMax('a', 'b') << std::endl;

	Storage<int> nValue(5);
	Storage<double> dValue(3.44);

	nValue.print();
	dValue.print();


	return 0;
}