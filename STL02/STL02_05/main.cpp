#include <iostream>
#include <list>
using namespace std;

/* c++17과 STL */

// c++17부터는 클래스 템플릿도 템플릿 인자를 명시적으로 지정하지 않아도 컴파일러가 추론 가능
// List 클래스의 T로부터 인자 추론 

template<typename T> class List
{
public:
	List(int sz, T initValue) {};
};

int main()
{
	List<int> s1(10, 0);
	List      s2(10, 0); //c++17 부터 가능

	list<int> s3 = { 1,2,3 };
	list	  s4 = { 1 ,2, 3 }; //c++17 부터 가능

	return 0;
}