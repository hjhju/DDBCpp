#include <iostream>
#include <string>

using namespace std;

/* Section17_03 std::string�� ���̿� �뷮  */

int main()
{
	string my_str("012345678");
	cout << my_str.size() << endl; // c���ʹ� �޸� null �� ������� ���� ���� ����

	cout << boolalpha;  // true or false�� ��µǰ���
	cout << my_str.empty() << endl; 

	cout << my_str.length() << endl;  // 9
	cout << my_str.capacity() << endl;  // 15  -> os�� ���� �޶���, ������ �뷮�� �δ� ��, memory reallocation�� ���ϱ� ����

	cout << my_str.max_size() << endl;

	my_str.reserve(1000); // �뷮 ����
	cout << my_str.size() << endl; // 9
	cout << my_str.length() << endl;  // 9
	cout << my_str.capacity() << endl;  // 1007

	return 0;
}