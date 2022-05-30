#include <iostream>
#include <thread>
#include <functional> // for ref

/* 05_std::ref */
// call by value�� ����ϴ� �Լ� ���ø��� ��ü�� ������ ������ ������ ���
// 

using namespace std;
using namespace std::literals;

void foo(int& a) { a = 200; }

template<typename T> void call_foo(T arg)
{
	foo(arg);
}

template<typename T> reference_wrapper<T> ref2(T& obj)
{
	return reference_wrapper<T>(obj);
}

int main()
{
	int n = 0;

	//call_foo(std::ref(n));
	//cout << n << endl;

	//reference_wrapper<int> rw = n; // ��ü�� �ּҸ� �����ϰ� ����
	//int& r = rw; // rw.operator int&(), T&�� �Ͻ��� ��ȯ�� ����
	//r = 100;

	//call_foo(rw);
	call_foo(ref2(n)); // std::ref(n);

	cout << n << endl;

	return 0;
}