#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

/* insert iterator 원리 */

// 모든 반복자는 *로 요소에 접근가능하고 ++ 연산자로 이동가능해야 한다.
// 삽입 반복자의 연산 ++, *, =
// member type 작성
	//using iterator_category = output_iterator_tag;
	//using value_type = void;
	//using pointer = void;
	//using reference = void;
	//using difference_type = void;
	//using container_type = C;

template<typename C>
class eback_insert_iterator
{
	C* container;
public:
	// g++의 경우 아래의 member type을 작성해야 에러가 안뜸
	using iterator_category = output_iterator_tag;
	using value_type = void;
	using pointer = void;
	using reference = void;
	using difference_type = void;
	using container_type = C;

	// eback_insert_iterator(C& c) :container(&c) {}
	explicit eback_insert_iterator(C& c) :container(std::addressof(c)) {} //c.operator&()

	eback_insert_iterator& operator*() { return *this; }
	eback_insert_iterator& operator++() { return *this; }
	eback_insert_iterator& operator++(int) { return *this; }
	eback_insert_iterator& operator=(const typename C::value_type& a)
	{
		container->push_back(a);
		return *this;
	}
	eback_insert_iterator& operator=(const typename C::value_type&& a) // move 대입
	{
		container->push_back(move(a));
		return *this;
	}
};

int main()
{
	list<int> s = { 1,2 };
	eback_insert_iterator<list<int>> p(s);
	*p = 30; // (p.operator*()).operator = (30) //30은 rvalue

	int x[2] = { 1,2 };
	copy(x, x + 2, p);

	for (auto& n : s)
	{
		cout << n << endl;
	}

	return 0;
}