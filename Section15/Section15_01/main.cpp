#include "Resource.h"
#include "AutoPtr.h"

using namespace std;

/* Section15_01 : 이동의 의미와 스마트 포인터 */


// RAII : resource acquistion is initialization

void doSomething()
{
	try
	{
		// Resource * res = new Resource; // dull (멍청한) pointer 
		// AutoPtr<Resource> res = new Resource; //smart pointer
		AutoPtr<Resource> res (new Resource); //smart pointer

											  // work with res
		if (true)
		//if (false)
		{
			//return; // early return
			throw - 1; // exception
		}

		//delete res;
	}
	catch (...)
	{

	}
	return;
}

int main()
{
	//doSomething();

	AutoPtr<Resource> res1(new Resource); // int i; int *ptr1(&i); int *ptr2=nullptr;
	AutoPtr<Resource> res2;

	cout << std::boolalpha;

	cout << res1.m_ptr << endl; // 유효한 주소
	cout << res2.m_ptr << endl; // nullptr

	// res2도 소유권을 가지게 됨
	// 지운것을 또 지우려고 하니 런타임 에러가 발생
	res2 = res1;  // move semantics

	cout << res1.m_ptr << endl;
	cout << res2.m_ptr << endl;

	// syntax vs semantics
	// syntax : 문법, 컴파일이 되는지 않되는지
	// sematics : 문법, 컴파일보단 의미가 중요

	// +에 대한 표현은 같지만 의미는 다름
	//int x = 1, y = 1;
	//x + y;

	//string str1("Hello"), str2("World");
	//str1 + str2; //append

	//doSomething(res1);
	// value semantics (Copy semantics)
	// reference semantics (pointer)
	// move semantics (move)

	return 0;
}