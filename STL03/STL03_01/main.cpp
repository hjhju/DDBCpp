#include <iostream>
#include <list>
#include <vector>
//#include <experimental/filesystem>

using namespace std;
//using namespace std::experimental::filesystem;

/* iterator basic  */

// iterator in GoF's Design Pattern 
// 복합 개체의 내부 구조에 상관없이 순차적으로 요소에 접근하기 위한 방법을 제공하는 것

// iterator in STL
// 반복자 처럼 동작하는 모든 것은 반복자이다.
// ++연산자로 이동가능하고, *연산자로 요소에 접근 가능한 것 

int main()
{
	int x[5] = { 1,2,3,4,5 };
	int* p = x;
	cout << *p << endl;
	cout << *(++p) << endl;

	//list<int> s = { 1,2,3,4,5 };
	vector<int> s = { 1,2,3,4,5 };
	//list<int>::iterator p2 = s.begin();
	//cout << *p2 << endl;
	//cout << *(++p2) << endl;

	// c++17부터 제공
	//directory_iterator p3("C://windows");
	//cout << *p3 << endl;
	//cout << *(++p3) << endl;

	// 컨테이너에서 반복자 꺼내기
	// c++11 부터 auto 사용 가능
	auto p4 = s.begin(); // 진짜 배열은 error

	auto p5 = begin(x);
	int n = size(x);
	cout << *p5 << endl;
	cout << n << endl;

	auto p6 = end(x);
	cout << *p6 << endl; // 마지막 다음을 가리킴 error


	// 반복자의 무효화 
	s.resize(100);
	cout << *p4 << endl; // 버퍼 재할당 error, 무효화된 반복자



	return 0;
}