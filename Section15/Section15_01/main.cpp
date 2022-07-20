#include "Resource.h"
#include "AutoPtr.h"

using namespace std;

/* Section15_01 : �̵��� �ǹ̿� ����Ʈ ������ */


// RAII : resource acquistion is initialization

void doSomething()
{
	try
	{
		// Resource * res = new Resource; // dull (��û��) pointer 
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

	cout << res1.m_ptr << endl; // ��ȿ�� �ּ�
	cout << res2.m_ptr << endl; // nullptr

	// res2�� �������� ������ ��
	// ������� �� ������� �ϴ� ��Ÿ�� ������ �߻�
	res2 = res1;  // move semantics

	cout << res1.m_ptr << endl;
	cout << res2.m_ptr << endl;

	// syntax vs semantics
	// syntax : ����, �������� �Ǵ��� �ʵǴ���
	// sematics : ����, �����Ϻ��� �ǹ̰� �߿�

	// +�� ���� ǥ���� ������ �ǹ̴� �ٸ�
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