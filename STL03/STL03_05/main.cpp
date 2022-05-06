#include <iostream>
#include <iterator>
using namespace std;

/* �ݺ��ڿ� member type */

// STL02_02���� ���� slist_iterator ����
// �ݺ��ڸ� ���� �� �ݵ�� member type�� �����ؾ��Ѵ�.

// iterator class
// - <iterator> ���
// - ��� �ݺ����� ��� Ŭ���� - c++17��������, c++17���ʹ� ������ ����

template<typename T> struct Node
{
	T data;
	Node* next;

	Node(const T& a, Node* n) : data(a), next(n) {} // ������
};

// <iterator> ���� ��� ������
/*
template<typename Category, 
		typename T, 
		typename Distance = std::ptrdiff_t, 
		typename Pointer = T*,
		typename Reference = T&
>
struct iterator
{
	// member type ����
	using iterator_category = forward_iterator_tag; // <iterator>, single list�ϱ� forward
	using value_type = T;
	using pointer = Pointer;
	using Reference = T&;
	using difference_type = Distance;
};
*/

// iterator ���
template<typename T> class slist_iterator : public iterator<forward_iterator_tag, T> 
{
	Node<T>* current = 0;
public:

	slist_iterator(Node<T>* p = 0) :current(p) {}
	slist_iterator& operator++() // ������ ������ ����
	{
		current = current->next;
		return *this;
	}
	T& operator*()
	{
		return current->data;
	}
	bool operator == (const slist_iterator& it)
	{
		return current == it.current;
	}
	bool operator != (const slist_iterator& it)
	{
		return current != it.current;
	}

};


/* �˰���� category */

// typename �ۼ��� �ǹ��ִ� Ű����� �ۼ��ϴ� ���� ����
template<typename InputIt, typename T>
InputIt efind(InputIt first, InputIt last, T value)
{
	while (first != last && *first != value)
		++first;
	return first;
}

int main()
{
	int x[3] = { 1,2,3 };
	int* p = efind(x, x + 3, 2);

	cout << *p << endl;


	return 0;
}