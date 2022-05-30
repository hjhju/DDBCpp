#include <iostream>
#include <thread>
#include <chrono>


/* 03_thread */

// 스레드 생성 방법
// std::thread의 생성자 인자로 스레드로 수행할 함수 전달
// join이나 detach가 필요
// join() : 스레드 종료를 대기
// detach() : 스레드를 떼어냄 (생성된 스레드가 독립적으로 실행)

using namespace std;
using namespace std::literals;


void foo()
{
	for (int i = 0; i < 10; i++)
	{
		cout << "foo : " << i << endl;
		std::this_thread::sleep_for(100ms);
	}
}

void f1() {}
void f2(int a, double d) {}
void f3(int a, int& b, std::string&& s) { b = 100; }


void foo2(int a, double d) {}

struct Machine
{
	void Run(int a, double d) {}
};

struct Work
{
	void operator()(int a, double b) const {}
};

int main()
{
	/*
	std::thread t(&foo);
	// 스레드 대기
	t.join();
	// 주 스레드 종료 시 프로세스 종료, detach()된 스레드가 강제로 종료
	t.detach();
	cout << "end" << endl;
	*/

	/*
	int n = 0;
	std::string s = "hello";

	std::thread t1(&f1);
	std::thread t2(&f2, 10, 3.4);
	// 스레드 함수에 인자를 참조로 전달할때는 std::ref, std::move를 사용해야됨
	std::thread t3(&f3, 10, std::ref(n), std::move(s));
	t1.join();
	t2.join();
	t3.join();

	std::cout << s << std::endl; // move로 보내면 자원 손실이 일어나므로 " "이 출력됨 
	std::cout << n << std::endl;
	*/

	// 일반 함수 뿐만 아니라 다양한 함수를 스레드로 수행 가능
	Machine m;
	Work w; w(1, 3.4);
	std::thread t1(&foo2, 1, 3.4); // 일반 함수
	std::thread t2(&Machine::Run, &m, 1, 3.4); // 멤버 함수
	std::thread t3(w, 1, 3.4); // 함수 객체
	std::thread t4([] {cout << "lambda" << endl; }); //람다 표현식
	t1.join();
	t2.join();
	t3.join();
	t4.join();



	return 0;
}