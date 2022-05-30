#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h> //for GetCurrentThread()

/* 04_thread */

using namespace std;
using namespace std::literals;

void foo()
{
	cout << this_thread::get_id() << endl;
}

void foo2()
{
	auto tid = std::this_thread::get_id();
	auto handle = GetCurrentThread(); 
	std::this_thread::sleep_for(1s);
	cout << GetThreadPriority(handle) << endl; // 현재 스레드의 우선순위가 얼마인지 출력
}


int main()
{
	/*
	int n = thread::hardware_concurrency(); // cpu가 지원하는 thread 개수, static
	cout << n << endl;

	thread t(&foo); //함수 foo를 실행하는 것은 스레드 t
	this_thread::sleep_for(1s);

	thread::id tid = t.get_id();
	cout << "created thread id : " << tid << endl;
	t.join();
	*/

	thread t(&foo2);
	thread::native_handle_type h = t.native_handle();

	cout << "ID : " << t.get_id() << endl;
	cout << "handle : " << h << endl;

	this_thread::sleep_for(100ms);
	SetThreadPriority((HANDLE)h, THREAD_PRIORITY_TIME_CRITICAL); // windows에서의 값은 15
	t.join();

	return 0;
}