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
		//std::forward는 t가 어떤 value로 들어온것인지 구분하여 전달함
		func(std::forward<T>(t));
	}

}