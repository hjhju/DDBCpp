#include <iostream>
#include <utility>

/* std::pair */
// 서로 다른 타입의 객체 2개를 보관하는 타임
// first, second 멤버를 통해 요소에 접근
// 함수가 2개의 값을 리턴하고 싶을때 pair를 리턴

using namespace std;

template<typename T> void foo(T p)
{
	cout << p.first << ", " << p.second << endl;
}

/*
// 함수 템플릿
template<typename T1, typename T2>
pair<T1, T2> make_pair ( const T1& a, const T2& b)
{
 return pair<T1, T2>(a, b);
}
*/

int main()
{
	pair<int, double> p1(1, 3.4);

	cout << p1.first << endl;
	cout << p1.second << endl;

	foo(p1);

	// make_pair
	// pair를 만드는 helper 함수
	// 클래스 템플릿은 템플릿 인자를 생략할 수 없으므로 복잠
	// 하지만, 함수 템플릿은 템플릿 인자를 생략할 수 있으므로 사용하기 쉬움

	foo(make_pair(1, 1));

	// c++17 부터는 클래스 템플릿도 인자를 생략 할 수 있다.
	foo(pair(2, 3.3));

	return 0;
}