#pragma once
#include <iostream>
using namespace std;

namespace Ex01 {

	struct MyStruct {

	};

	void func(MyStruct& s)
	{
		cout << "Pass by L - ref" << endl;
	}
	
	void func(MyStruct&& s)
	{
		cout << "Pass by R - ref" << endl;
	}

	template<typename T>
	void func_wrapper1(T t)
	{
		func(t);
	}

	template<typename T>
	void func_wrapper2(T&& t)
	{
		//std::forward�� t�� � value�� ���°����� �����Ͽ� ������
		func(std::forward<T>(t));
	}

}