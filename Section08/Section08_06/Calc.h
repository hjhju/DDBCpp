#pragma once

#include <iostream>

// 통상적으로 헤더파일에는 using namespace std; 잘 안씀
// 모든 곳에 영향을 주기 때문

class Calc
{
private:
	int m_value;
public:
	Calc(int init_value);

	Calc& add(int value);

	Calc& sub(int value);

	Calc& mul(int value);

	void print();
};


