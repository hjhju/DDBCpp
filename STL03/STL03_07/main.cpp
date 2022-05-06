#include <iostream>
#include <list>
#include <iterator>

using namespace std;

/* insert iterator */

// 컨테이너 요소를 추가하는 방법
//  - 멤버 함수 (push_xxx,/ emplace_Xxx/ insert) 사용
//  - 삽입 반복자 (insert iterator)

// 삽입 반복자
//  - <iterator> 헤더
//  - 컨테이너에 요소를 삽입할 때 사용하는 반복자
//  - 3가지 종류 (전방, 후방, 임의 삽입) 제공

// 기본 모양
//   - back_insert_iterator<컨테이너 클래스 이름> p(컨테이너 객체)

/* 
// c++ 표준에 제공됨 
template<typename T>
back_insert_iterator<T>
back_inserter(T& c)
{
	return back_insert_iterator<T>(c);
}
*/


int main(int argc, char **argv)
{
	list<int> s = { 1,2,3,4,5 };
	s.push_back(10);

	back_insert_iterator<list<int>> p(s); // 삽입 반복자

	*p = 20; // s.push_back(20)과 동일


	int x[5] = { 10,20,30,40,50 };

	// for (int i = 0; i < 5; i++)
	//		s.push_back(x[i]);


	// 삽입반복자를 쓰면 위와 같은 반복문을 쓰지 않고 한번에 삽입 가능
	copy(x, x + 5, p); 

	//copy(x, x + 5, s.begin()); // 덮어쓰는 것

	// 살전 코딩에서는 이렇게 사용
	copy(x, x + 5, back_inserter(s)); 

	// 전방 삽입의 경우 x의 순서가 역순으로 삽입됨
	//copy(x, x + 5, front_inserter(s));

	// 임의 삽입의 경우 생성자 인자가 2개 필요 - 컨테이너와 삽입할 위치를 나타내는 반복자
	// 전방 삽입과 다르게 순서가 뒤집히지 않음
	copy(x, x + 5, inserter(s, s.begin())); 


	for (auto& n : s)
	{
		cout << n << endl;
	}

	return 0;
}