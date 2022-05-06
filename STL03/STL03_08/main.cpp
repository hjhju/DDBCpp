#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

/* insert iterator ���� */

// ��� �ݺ��ڴ� *�� ��ҿ� ���ٰ����ϰ� ++ �����ڷ� �̵������ؾ� �Ѵ�.
// ���� �ݺ����� ���� ++, *, =
// member type �ۼ�
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
	// g++�� ��� �Ʒ��� member type�� �ۼ��ؾ� ������ �ȶ�
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
	eback_insert_iterator& operator=(const typename C::value_type&& a) // move ����
	{
		container->push_back(move(a));
		return *this;
	}
};

int main()
{
	list<int> s = { 1,2 };
	eback_insert_iterator<list<int>> p(s);
	*p = 30; // (p.operator*()).operator = (30) //30�� rvalue

	int x[2] = { 1,2 };
	copy(x, x + 2, p);

	for (auto& n : s)
	{
		cout << n << endl;
	}

	return 0;
}