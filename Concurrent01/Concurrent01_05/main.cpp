#include <iostream>
#include <thread>
#include <functional> // for ref

/* 05_std::ref */
// call by value를 사용하는 함수 템플릿에 객체를 참조로 보내고 싶을때 사용
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

	//reference_wrapper<int> rw = n; // 객체의 주소를 보관하고 있음
	//int& r = rw; // rw.operator int&(), T&로 암시적 변환이 가능
	//r = 100;

	//call_foo(rw);
	call_foo(ref2(n)); // std::ref(n);

	cout << n << endl;

	return 0;
}