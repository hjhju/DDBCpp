#include <iostream>
#include <thread>
#include <chrono>

/* 02_std::chrono */

using namespace std;
using namespace std::literals;


int main()
{
	// chrono ���̺귯���� ��� �ð� Ÿ���� duration<>�� alias
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

	// �Ʒ��� ���� ǥ�� ���� (�ι�°�� ���� ���)
	std::this_thread::sleep_for(std::chrono::duration<long long>(10));
	std::this_thread::sleep_for(std::chrono::seconds(10));
	std::this_thread::sleep_for(10s);

	// ++17 ���� ����
	std::chrono::time_point tp1 = std::chrono::system_clock::now(); // ���� �ð��� ��� ���

	std::chrono::hours h2 = std::chrono::duration_cast<std::chrono::hours>(tp1.time_since_epoch()); //1970�� 1�� 1�� ����
	cout << h2.count() << endl;


	return 0;
}