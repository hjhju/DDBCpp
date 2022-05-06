#include <iostream>
#include <list>
#include <vector>
#include <iterator>
using namespace std;

/* tag dispatching */

/* advance �Լ� 
  - <iterator> ���
  - �ݺ��� N��ŭ ����(����)�ϴ� �Լ�
�ݺ��ڸ� �̵��� ��
  - + : ���� ���� �ݺ��ڸ� ����
  - ++ : ��� �ݺ��ڰ� ����������, ���� ���� �ݺ����� ��� +�� �̵��ϴ� ���� ����
  - ���� ���� �ݺ����� ���� �׷��� ���� ��츦 �ٸ��� �����ؾߵ� - tag dispatching ����� ���
*/

/* iterator category tag */
// <iterator> ���
// �ݺ����� 5���� category�� ��Ÿ���� Ÿ��, empty class�� ����
// c++17���� �߰��� contiguous iterator�� ������ tag�� �������� ����

/*
// 5���� category Ÿ��

struct input_iterator_tag {}; // empty class
struct output_iterator_tag {};
struct forward_iterator_tag
	: public input_iterator_tag {};
struct bidirectional_iterator_tag
	: public forward_iterator_tag{};
struct random_access_iterator_tag
	: public bidirectional_iterator_tag {};


// �ݺ��ڸ� ���鶧... �ڽ��� category�� �˷��ش�.

template<typename T> class vector_iterator
{
public:
	using iterator_category = random_access_iterator_tag;
};

template<typename T> class list_iterator
{
public:
	using iterator_category = bidirectional_iterator_tag;
};

*/

/* tag dispatching ��� ���� - "c++ template programming ����" ���� */

// 1. �Լ� ���ڸ� ����� �����ε�
/*
template<typename T>
void eadvance_imp(T& p, int n, random_access_iterator_tag)
{
	cout << "random"<< endl;
	p = p + n;
}
template<typename T>
void eadvance_imp(T& p, int n, input_iterator_tag)
{	
	cout << "input" << endl;
	while (n--)
		++p;
}
template<typename T>
void eadvance(T& p, int n)
{
	// �ݺ����� ������ ���� �ٸ� �Լ��� ����
	eadvance_imp(p, n, typename T::iterator_category());
}
*/

// 2. C++17 if constexpr ���
/*
#include <type_traits>
template<typename T>
void eadvance(T& p, int n)
{
	if constexpr (is_same<T::iterator_category, random_access_iterator_tag>::value)
	{
		p = p + n;
	}
	else
	{
		while (n--)
			++p;
	}
}
*/

// 3. enable if�� ��� - SFINAE ���� ���.
template<typename T>
typename enable_if<is_same<typename T::iterator_category, random_access_iterator_tag>::value>::type
eadvance(T& p, int n)
{
	p = p + n;
}

template<typename T>
typename enable_if<is_same<typename T::iterator_category, input_iterator_tag>::value>::type
eadvance(T& p, int n)
{
	while (n--)
		++p;
}

int main()
{
	//list<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = begin(s);

	// �ݺ��� p�� 5ĭ �����ϰ� �ʹ�.
	
	// p = p + 5;
	//advance(p, 5);
	eadvance(p, 5); // vector�� random, list�� input

	cout << *p << endl;
	
	

	return 0;
}