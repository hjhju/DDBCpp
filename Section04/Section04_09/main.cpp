#include <iostream>
#include <vector>

using namespace std;

/* Section04_09 : 자료형에게 가명 붙여주기 */


int main()
{
	// 별명이라고 생각하면 됨

	typedef double distance_t; //_t는 타입을 의미

	std::int8_t i(97); // 고정너비변수

	double		my_distance;
	distance_t	home2work;
	distance_t	home2school;
	
	// home2~ 두변수가 float이 되어야한다면 typedef float distance_t;으로 수정하면 됨


	// 복잡한 자료형을 다음과 같이 표기 가능 
	//1)
	//typedef vector<pair<string, int>> pairlist_t;
	//2) using으로도 표현 가능
	using pairlist_t = vector<pair<string, int>>;

	pairlist_t pairlist1;
	pairlist_t pairlist2;

	
	return 0;
}