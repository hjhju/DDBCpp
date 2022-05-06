#include <iostream>

using namespace std;

/* Section07_06 인라인 함수 */

// 헤더파일에 함수 정의시 주로 사용
// inline으로 처리하면 함수가 아닌 것 처럼 작동
// inline을 쓰면 빨라진다고 알려짐, 최근에는 쓴다고 무조건 빨라진다는 보장은 없음

inline int min(int x, int y)
{
	return x > y ? y : x;
}

int main()
{
	cout << min(5, 6) << endl;
	// cout<<(5 > 6 ? 6 : 5;)<<endl; 처럼 작동
	cout << min(3, 2) << endl;

	return 0;
}