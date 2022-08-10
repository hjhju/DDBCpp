#include <iostream>
#include <string>

using namespace std;

/* Section17_03 std::string의 길이와 용량  */

int main()
{
	string my_str("012345678");
	cout << my_str.size() << endl; // c언어와는 달리 null 값 고려없이 문자 길이 리턴

	cout << boolalpha;  // true or false로 출력되게함
	cout << my_str.empty() << endl; 

	cout << my_str.length() << endl;  // 9
	cout << my_str.capacity() << endl;  // 15  -> os에 따라 달라짐, 여분의 용량을 두는 것, memory reallocation을 안하기 위해

	cout << my_str.max_size() << endl;

	my_str.reserve(1000); // 용량 늘임
	cout << my_str.size() << endl; // 9
	cout << my_str.length() << endl;  // 9
	cout << my_str.capacity() << endl;  // 1007

	return 0;
}