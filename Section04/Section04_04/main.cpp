#include <iostream>

using namespace std;

/* Section04_03 : Using문과 모호성 */
/* Section04_04 : auto 키워드와 자료형 추론 */


namespace a
{
	int my_var(10);
}

namespace b
{
	int my_var(30);
}


// auto add(int x, int y) -> int;
// auto add(double x, double y) -> double;

// auto는 파라미터 타입에서는 쓸 수 없음
auto add(int x, int y) -> int
{
	return x + y;
}

auto add(double x, double y) -> double
{
	return x + y;
}

int main()
{
	using namespace a;
	using namespace b;

	cout << a::my_var << endl;
	cout << b::my_var << endl;

	auto n = 123; // 선언만 하고 초기화하지 않으면 사용할 수 없음
	auto m = 123.0;
	auto l = 1 + 2.0;

	cout << n << endl;

	auto result = add(1, 2);
	cout << result << endl;

	auto result2 = add(1.3, 2.2);
	cout << result2 << endl;

	return 0;
}