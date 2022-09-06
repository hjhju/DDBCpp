#include <iostream>
#include <chrono>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <vector>
#include <atomic>
#include <future>
#include <numeric>  // std::inner_product
#include <execution> // parallel execution

using namespace std;

/* Section19_06 멀티쓰레딩 예제 (벡터 내적 계산)  */

mutex mtx;

void dotProductNaive(const vector<int> & v0, const vector<int> &v1, const unsigned i_start,
	const unsigned i_end, unsigned long long &sum)
{
	for (unsigned i = i_start; i < i_end; i++)
		sum += v0[i] * v1[i];
}

void dotProductLock(const vector<int>& v0, const vector<int>& v1, const unsigned i_start,
	const unsigned i_end, unsigned long long& sum)
{
	//cout<< "Thread start " <<endl;
	for (unsigned i = i_start; i < i_end; i++)
	{
		std::scoped_lock lock(mtx);  // lock의 위치가 실행시간에 많은 영향을 미침!!
		sum += v0[i] * v1[i];
	}
	//cout<< "Thread end " <<endl;

}

void dotProductAtomic(const vector<int>& v0, const vector<int>& v1, const unsigned i_start,
	const unsigned i_end, atomic<unsigned long long>& sum)
{
	for (unsigned i = i_start; i < i_end; i++)
		sum += v0[i] * v1[i];
}

auto dotProductFuture(const vector<int>& v0, const vector<int>& v1, const unsigned i_start,
	const unsigned i_end)
{
	int sum = 0; // local sum
	for (unsigned i = i_start; i < i_end; i++)
		sum += v0[i] * v1[i];

	return sum;
}

int main()
{
	/*
		v0 = { 1, 2, 3 };
		v1 = { 4, 5, 6 };
		v0_dot_v1 = 1 * 4 + 2 * 5 + 3 * 6;
	*/

	//const long long n_data = 100'000'000;
	const long long n_data = 1000000;

	const unsigned n_threads = 4;

	// initialize vectors
	std::vector<int> v0, v1;

	v0.reserve(n_data);
	v1.reserve(n_data);

	random_device seed;
	mt19937 engine(seed());

	uniform_int_distribution<> uniformDist(1, 10);
	
	// 랜덤 값으로 이루어진 2개의 벡터 생성
	for (long long i = 0; i < n_data; i++)
	{
		v0.push_back(uniformDist(engine));
		v1.push_back(uniformDist(engine));
	}

	
	cout << "1. std::inner_product" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		// 0ull라고 표기를 해서 넣어줬기때문에 unsigned long long임을 알수 있다
		const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);
		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}
	

	cout << "2. Naive" << endl;
	{
		const auto sta = chrono::steady_clock::now();
		unsigned long long sum = 0;
		
		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads; // assumes remainder = 0
		for (unsigned t = 0; t < n_threads; ++t)
			threads[t] = std::thread(dotProductNaive, std::ref(v0), std::ref(v1),
				t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));

		for (unsigned t = 0; t < n_threads; ++t)
			threads[t].join();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;  // 답이 틀림!!
		cout << endl;
	}

	cout << "3. LockGuard" << endl;
	{
		const auto sta = chrono::steady_clock::now();
		unsigned long long sum = 0;

		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads; // assumes remainder = 0
		for (unsigned t = 0; t < n_threads; ++t)
			threads[t] = std::thread(dotProductLock, std::ref(v0), std::ref(v1),
				t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));

		for (unsigned t = 0; t < n_threads; ++t)
			threads[t].join();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	// 빈번하게 호출되는 부분에 automic 연산을 넣어주면 느려짐
	cout << "4. Atomic" << endl;
	{
		const auto sta = chrono::steady_clock::now();
		atomic<unsigned long long> sum = 0;

		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads; // assumes remainder = 0
		for (unsigned t = 0; t < n_threads; ++t)
			threads[t] = std::thread(dotProductAtomic, std::ref(v0), std::ref(v1),
				t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));

		for (unsigned t = 0; t < n_threads; ++t)
			threads[t].join();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	cout << "5. Future" << endl;
	{
		const auto sta = chrono::steady_clock::now();
		unsigned long long sum = 0;

		vector<std::future<int>> futures;
		futures.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads; // assumes remainder = 0
		for (unsigned t = 0; t < n_threads; ++t)
			futures[t] = std::async(dotProductFuture, std::ref(v0), std::ref(v1),
				t * n_per_thread, (t + 1) * n_per_thread);

		for (unsigned t = 0; t < n_threads; ++t)
			sum += futures[t].get();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	// std 자체에서 제공해주는 기능
	cout << "6. std::transform_reduce" << endl;
	{
		const auto sta = chrono::steady_clock::now();
		
		// sequential하게 돌려라
		//const auto sum = std::transform_reduce(std::execution::seq, v0.begin(), v0.end(), v1.begin(), 0ull);

		// 병렬로 돌려라
		const auto sum = std::transform_reduce(std::execution::par, v0.begin(), v0.end(), v1.begin(), 0ull);

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	return 0;
}