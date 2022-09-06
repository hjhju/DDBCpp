#include <iostream>
#include <tuple>
using namespace std;

/* Section19_02 c++17 �Լ����� �������� ���ϰ� ��ȯ�ϱ�  */


//tuple<int, int> my_func()
auto my_func()
{
	//return tuple<int,int>(123, 456);
	
	// c++17������ <int, int, ... > �̰� �Ƚᵵ ��
	//return tuple<int, int, int>(123, 456, 789);
	return tuple(123, 456, 789);

}

int main()
{
	cout << "Hello, world" << endl;

	//tuple<int, int> result = my_func();
	
	auto result = my_func();
	//cout << get<0>(result) << " " << get<1>(result) << endl;
	//cout << get<0>(result) << " " << get<1>(result) << " " << get<2>(result) << endl;

	// �Ʒ� ó�� ����ϸ� get<#>() �Ƚᵵ ��!
	auto [a, b, c] = my_func();
	cout << a << " " << b << " " << c << endl;



	return 0;
}