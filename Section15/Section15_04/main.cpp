#include <iostream>
#include "AutoPtr.h"
#include "Resource.h"
#include <vector>

using namespace std;

/* Section15_04 std::move */

template<class T>
void MySwap(T& a, T& b)
{
	// 1) copy를 사용
	//T tmp = a;
	//a = b;
	//b = tmp;

	// 2) move를 사용
	T tmp{ std::move(a) };
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	//{
	//	AutoPtr<Resource> res1(new Resource(10000000));
	//	cout << res1.m_ptr << endl;

	//	//AutoPtr<Resource> res2 = res1;
	//	// std::move는 res1을 L-value가 아닌 R-value를 사용하는 것 처럼 보이게 함
	//	AutoPtr<Resource> res2 = std::move(res1);

	//	cout << res1.m_ptr << endl;
	//	cout << res2.m_ptr << endl;
	//}

	//{
	//	AutoPtr<Resource> res1(new Resource(3));
	//	res1->setAll(3);

	//	AutoPtr<Resource> res2(new Resource(5));
	//	res2->setAll(5);
	//	cout << endl;

	//	res1->print();
	//	res2->print();
	//	
	//	MySwap(res1, res2);
	//	cout << endl;
	//	res1->print();
	//	res2->print();
	//}

	//{
	//	vector<string> v;
	//	string str = "Hello";

	//	v.push_back(str);

	//	cout << str << endl;
	//	cout << v[0] << endl;

	//	v.push_back(std::move(str));
	//	// move를 썼기에 str에 null이 들어감 (push_back이 그렇게 되도록 짜여진 코드이기때문)
	//	cout << str << endl; 
	//	cout << v[0] << " "<< v[1]<<endl;
	//}

	{
		std::string x{ "abc" };
		std::string y{ "de" };

		std::cout << "x : " << x << std::endl;
		std::cout << "y : " << y << std::endl;

		MySwap(x, y);

		std::cout << "x : " << x << std::endl;
		std::cout << "y : " << y << std::endl;

	}


	return 0;
}