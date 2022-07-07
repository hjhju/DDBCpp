#include <iostream>
#include "Cents.h"

/* Section 13_01 함수 템플릿 */

template <typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

int main()
{
	std::cout << getMax(1, 2) << std::endl;
	std::cout << getMax(3.14, 1.59) << std::endl;
	std::cout << getMax(1.2f, 3.5f) << std::endl;
	std::cout << getMax('a', 'b') << std::endl;

	std::cout << getMax(Cents(5), Cents(9)) << std::endl;


	return 0;
}