#include <iostream>
#include <cstdlib> //std::radn(), std::srand()
#include <ctime> // std::time()
#include <random>
using namespace std;

/* Section05_09 난수 만들기 */

// 난수 만드는 원리
unsigned int PRNG() //Pseudo Random Number Generator
{
	// 계속 바뀌는 값을 만들기위해 static 사용
	static unsigned int seed = 5523; // seed number

	seed = 8353729 * seed + 2396403;

	return seed % 32768;
}

// 나누기는 좀 느림 -> static 또는 전역 상수 만들어서 사용해도 됨
// const double fraction = 1.0 / (RAND_MAX);

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (RAND_MAX+1.0);

	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

int main()
{
	// seed로 고정된 값을 사용하면 계속 같은 값이 나옴
	// 디버깅이 필요할때는 고정시켜서 사용하는 것이 좋음
	// std::srand(5323); // seed 설정 
	std::srand(static_cast<unsigned int>(std::time(0))); //시간이 흘러가는 것을 활용해서 seed 변경

	for (int count = 1; count <= 100; ++count)
	{
		//cout << std::rand() % 5 + 2 << '\t';
		cout << getRandomNumber(2,8) << '\t';
		if (count % 5 == 0)
			cout << endl;
	}

	/* c++11부터 생긴 random 라이브러리*/

	std::random_device rd; // seed를 위한 별도의 랜덤 디바이스 제공 (time 연동과 유사)
	// mt19937은 32bit random number 생성해줌
	// create a mesenne twister 
	std::mt19937 mersenne(rd()); 

	std::uniform_int_distribution<> dice(1, 6); // 1~6까지 나올 확률이 동일

	for (int count = 1; count <= 20; ++count)
	{
		cout << dice(mersenne) << endl;
	}



	return 0;
}