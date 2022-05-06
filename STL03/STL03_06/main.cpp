#include <iostream>
#include <list>
#include <vector>
#include <iterator>
using namespace std;

/* iterator_traits */

//  - <iterator> ���
//  - raw pointer���� "member type�� ���ٴ� ������ �ذ��ϱ����� ����
//  - �ݺ����� value type�� �ʿ��Ҷ�, iterator_traits�� ���� value_type�� ���

// value_type�� ����ϴ� 2���� ���
//  - T::value_type : T�� Raw pointer��� error
//  - iterator_traits<T>::value_type : T�� Raw pointer�� ���� ����


/*
template<typename T> struct iterator_traits
{
	using value_type = typename T::value_type;
};

// �ٽ� : ������ ������ �κ� Ư��ȭ
template<typename T> struct iterator_traits<T*>
{
	using value_type = T;
};
*/

template<typename T>
typename iterator_traits<T>::value_type sum(T first, T last)
{
	// ������ ���� ������ ����
	// T:�ݺ��� Ÿ��
	// T::value_type : �ݺ��ڰ� ����Ű�� Ÿ��
	// typename T::value_type s = 0;

	//typename iterator_traits<T>::value_type s = 0;

	// value_type ��ſ� auto/decltype�� ����� ���
	// type deduction��Ģ�� ��Ȯ�� �˰� ����ؾ� �Ѵ�!!
	
	// decltype(*first) s = 0; // decltype(*������Ÿ��) error!
	typename remove_reference<decltype(*first)>::type s = 0;
	
	while (first != last)
	{
		s = s + *first;
		++first;
	}
	return s;
}


template<typename T>
void foo(T a)
{
	// T�� �ݺ��� �϶� �ݺ��ڰ� ����Ű�� Ÿ���� ����ϰ� �ʹ�.
	typename T::value_type n1;
	typename iterator_traits<T>::value_type n2;

}

template<typename T>
void eadvance_imp(T& p, int n, random_access_iterator_tag)
{
	cout << "random" << endl;
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
	eadvance_imp(p, n, typename iterator_traits<T>::iterator_category());
}

int main()
{
	//list<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	//vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	int s[10] = { 1,2,3,4,5,6,7,8,9,10 };

	// raw pointer���� member type�� �����Ƿ� �˰��� �Լ��� ���鶧 ������ ����
	int n = sum(begin(s), end(s)); 
	cout << n << endl;

	auto p = begin(s);
	eadvance(p, 5);
	cout << *p << endl;

	return 0;
}