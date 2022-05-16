#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono> // (크로노) 시간 재는 라이브러리

using namespace std;

/* Section08_15 실행 시간 측정하기 */

// 벡터 sorting 하는 시간 측정하는 예제

class Timer
{
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;

	std::chrono::time_point<clock_t> start_time = clock_t::now();

public:
	void elapsed()
	{
		std::chrono::time_point<clock_t> end_time = clock_t::now();

		// 초로 변환해서 출력
		cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() <<"sec"<< endl;
	}
};

int main()
{
	random_device rnd_device;
	mt19937 mersenne_engine{ rnd_device() };

	vector<int> vec(100000);
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		vec[i] = i;
	}

	std::shuffle(begin(vec), end(vec), mersenne_engine); // rn generator 이용해서 셔플

	//for (auto& e : vec) cout << e << " ";
	//cout << endl;

	Timer timer;

	std::sort(begin(vec), end(vec));

	timer.elapsed();

	//for (auto& e : vec) cout << e << " ";
	//cout << endl;


	return 0;
}