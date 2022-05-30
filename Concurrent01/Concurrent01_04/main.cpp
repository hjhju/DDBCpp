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
	cout << GetThreadPriority(handle) << endl; // ���� �������� �켱������ ������ ���
}


int main()
{
	/*
	int n = thread::hardware_concurrency(); // cpu�� �����ϴ� thread ����, static
	cout << n << endl;

	thread t(&foo); //�Լ� foo�� �����ϴ� ���� ������ t
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
	SetThreadPriority((HANDLE)h, THREAD_PRIORITY_TIME_CRITICAL); // windows������ ���� 15
	t.join();

	return 0;
}