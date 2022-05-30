#include <iostream>
#include <thread>
#include <chrono>

/* 02_std::chrono */

using namespace std;
using namespace std::literals;


int main()
{
	// chrono 라이브러리의 모든 시간 타입은 duration<>의 alias
	std::chrono::hours h(10);
	std::chrono::minutes m(10);
	std::chrono::seconds s1(10);
	std::chrono::milliseconds s2(10);
	std::chrono::nanoseconds s3(10);

	cout << s1.count() << endl;

	std::chrono::duration<long long> d1(10);

	auto a1 = 10s;
	auto a2 = 10ms;
	auto a3 = 10min;

	// 아래와 같이 표기 가능 (두번째를 많이 사용)
	std::this_thread::sleep_for(std::chrono::duration<long long>(10));
	std::this_thread::sleep_for(std::chrono::seconds(10));
	std::this_thread::sleep_for(10s);

	// ++17 부터 가능
	std::chrono::time_point tp1 = std::chrono::system_clock::now(); // 현재 시간을 얻는 방법

	std::chrono::hours h2 = std::chrono::duration_cast<std::chrono::hours>(tp1.time_since_epoch()); //1970년 1월 1일 이후
	cout << h2.count() << endl;


	return 0;
}