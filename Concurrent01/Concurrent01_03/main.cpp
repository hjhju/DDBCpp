#include <iostream>
#include <thread>
#include <chrono>


/* 03_thread */

// ������ ���� ���
// std::thread�� ������ ���ڷ� ������� ������ �Լ� ����
// join�̳� detach�� �ʿ�
// join() : ������ ���Ḧ ���
// detach() : �����带 ��� (������ �����尡 ���������� ����)

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
	// ������ ���
	t.join();
	// �� ������ ���� �� ���μ��� ����, detach()�� �����尡 ������ ����
	t.detach();
	cout << "end" << endl;
	*/

	/*
	int n = 0;
	std::string s = "hello";

	std::thread t1(&f1);
	std::thread t2(&f2, 10, 3.4);
	// ������ �Լ��� ���ڸ� ������ �����Ҷ��� std::ref, std::move�� ����ؾߵ�
	std::thread t3(&f3, 10, std::ref(n), std::move(s));
	t1.join();
	t2.join();
	t3.join();

	std::cout << s << std::endl; // move�� ������ �ڿ� �ս��� �Ͼ�Ƿ� " "�� ��µ� 
	std::cout << n << std::endl;
	*/

	// �Ϲ� �Լ� �Ӹ� �ƴ϶� �پ��� �Լ��� ������� ���� ����
	Machine m;
	Work w; w(1, 3.4);
	std::thread t1(&foo2, 1, 3.4); // �Ϲ� �Լ�
	std::thread t2(&Machine::Run, &m, 1, 3.4); // ��� �Լ�
	std::thread t3(w, 1, 3.4); // �Լ� ��ü
	std::thread t4([] {cout << "lambda" << endl; }); //���� ǥ����
	t1.join();
	t2.join();
	t3.join();
	t4.join();



	return 0;
}