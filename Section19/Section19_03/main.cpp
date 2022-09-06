#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>
using namespace std;

/* Section19_03 std::thread와 멀티쓰레딩 기초  */

// process : os를 실행할때 작동하는 것
// 하나의 process가 여러개의 thread를 관리한다.
// 멀티쓰레딩 : 하나의 cpu에서 여러개의 thread로 동시에 작업
// 멀티쓰레딩이 멀티 프로세싱보다 효율적


mutex mtx; // mutual exclusion (상호 배제)

int main()
{
	// 하드웨어 코어 수 출력
	const int num_pro = std::thread::hardware_concurrency();
	cout << num_pro << endl;

	// this thread의 id값 출력
	cout << std::this_thread::get_id() << endl;

	// 해야할 일을 매개변수로 주면 됨
	// 새로생긴 thread는 메인 thread와 소통을 해야함 -> join이용

	/*
	std::thread t1 = std::thread([]() { 
		cout << std::this_thread::get_id() << endl; 
		while (true) {}});

	std::thread t2 = std::thread([]() {
		cout << std::this_thread::get_id() << endl;
		while (true) {}});

	std::thread t3 = std::thread([]() {
		cout << std::this_thread::get_id() << endl;
		while (true) {}});

	std::thread t4 = std::thread([]() {
		cout << std::this_thread::get_id() << endl;
		while (true) {}});

	t1.join(); // t1이 끝날때 까지 기다려줌
	t2.join();
	t3.join();
	t4.join();

	*/

	/*
	vector<std::thread> my_threads;
	my_threads.resize(num_pro);
	
	for (auto& e : my_threads)
	{
		e = std::thread([]() {
			cout << std::this_thread::get_id() << endl;
			while (true) {}});
	}

	for (auto& e : my_threads)
		e.join();

	*/


	auto work_func = [](const string& name) {
		for (int i = 0; i < 5; i++)
		{
			// 잠시 쉬게 하기
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			// mutex는 lock, unlock 같이 써야됨
			mtx.lock();
			cout << name << " " << std::this_thread::get_id() << " is working " << i << endl;
			mtx.unlock();
		}
	};

	// 이렇게만 하면 한 쓰레드만 사용
	//work_func("JackJack");
	//work_func("Dash");

	std::thread t1 = std::thread(work_func, "JackJack");
	std::thread t2 = std::thread(work_func, "Dash");
	std::thread t3 = std::thread(work_func, "Kim");

	t1.join();
	t2.join();
	t3.join();



	return 0;
}