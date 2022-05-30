#include <iostream>
#include <thread>
#include <chrono>

/* 01_std::this_thread */

using namespace std;
using namespace std::literals;

std::chrono::system_clock::time_point
createDateTime(int year, int month, int day, int hour, int minute, int second);

int main()
{
	// std::this_thread::get_id() : 실행중인 현재 스레드의 ID를 반환
	// cout로 출력가능하고 비교 연산이 가능
	// 정수로 변환은 안됨
	// unordered 컨테이너에 키 값으로 사용가능

	cout << std::this_thread::get_id() << endl; 

	std::thread::id tid1 = std::this_thread::get_id();
	std::thread::id tid2 = std::this_thread::get_id();

	// 비교 연산가능
	tid1 = tid2;
	tid1 < tid2;

	std::hash<std::thread::id> h;
	cout << h(tid1) << endl;

	// sleep_for() : 주어진 시간 만큼 현재 스레드 멈추기 (재우기)
	// sleep_until() : 주어진 시간까지 현재 스레드 멈추기 (재우기)

	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::this_thread::sleep_for(3s); //
	//std::this_thread::sleep_for(3);

	std::chrono::time_point tp1 = std::chrono::steady_clock::now();
	std::this_thread::sleep_until(tp1 + 2000ms);

	auto tp2 = createDateTime(2021, 4, 11, 12, 39, 00);
	std::this_thread::sleep_until(tp2);


	return 0;
}

time_t toUTC(std::tm& timeinfo)
{
#ifdef _WIN32
	std::time_t tt = _mkgmtime(&timeinfo);
#else
	time_t tt = timegm(&timeinfo);
#endif
	return tt;
}


std::chrono::system_clock::time_point
createDateTime(int year, int month, int day, int hour, int minute, int second)
{
	tm timeinfo1 = tm();
	timeinfo1.tm_year = year - 1900;
	timeinfo1.tm_mon = month - 1;
	timeinfo1.tm_mday = day;
	timeinfo1.tm_hour = hour;
	timeinfo1.tm_min = minute;
	timeinfo1.tm_sec = second;
	tm timeinfo = timeinfo1;
	time_t tt = toUTC(timeinfo);
	return std::chrono::system_clock::from_time_t(tt);
}