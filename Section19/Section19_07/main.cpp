#include <iostream>
#include <vector>
#include <utility> // std::forward
#include "Ex01.h"
#include "Ex02.h"
using namespace std;

/* Section19_07 �Ϻ��� ���ް� std::forward  */


int main()
{
	cout << "Ex01" << endl;
	{
		Ex01::MyStruct s;

		Ex01::func(s); // L-value
		Ex01::func(Ex01::MyStruct());  // R-value

		// ���ø� ���� ���� �߻�
		Ex01::func_wrapper1(s); // L-value
		Ex01::func_wrapper1(Ex01::MyStruct()); // �̰�� L-value�� ����

		// std::forward �� Ȱ��
		Ex01::func_wrapper2(s); // L-value
		Ex01::func_wrapper2(Ex01::MyStruct()); // �̰�� L-value�� ����
	}
	cout << endl;

	cout << "Ex02" << endl;
	{
		Ex02::CustomVector my_vec(10, 1024);

		Ex02::CustomVector temp1(my_vec); // my_vec�� l-value
		cout << my_vec.n_data << endl;

		Ex02::CustomVector temp2(std::move(my_vec));
		cout << my_vec.n_data << endl; // my_vec�� ���� ����

		cout << endl;

		Ex02::doSomething(my_vec);
		Ex02::doSomething(Ex02::CustomVector(10, 8));
		cout << endl;
		Ex02::doSomethingTemplate(my_vec);
		Ex02::doSomethingTemplate(Ex02::CustomVector(10, 8));

	}

	return 0;
}