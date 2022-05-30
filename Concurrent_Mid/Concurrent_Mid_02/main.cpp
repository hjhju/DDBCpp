#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <vector>

using namespace std::literals;

#define MAX 100000000

void s_add(std::promise<long long>&& p, std::vector<int> v, int a, int b)
{
    long long s = 0;
    for (int i = a; i < b; i++) {
        s += v[i];
    }
    p.set_value(s);
}

long long m_add(std::vector<int> v, int a, int b)
{
    long long s = 0;
    for (int i = a; i < b; i++) {
        s += v[i];
    }
    return s;
}

int main()
{
    std::vector<int> v(MAX, 1);

    // Case A
    std::promise<long long> pm;
    std::future<long long> ft = pm.get_future();

    std::thread t(&s_add, std::move(pm), v, 0, MAX);
    long long ret = ft.get();
    std::cout << "Case A - single thread : " << ret << std::endl;
    t.join();

    // Case B
    std::future<long long> ft0 = std::async(std::launch::async, m_add, v, 0, MAX / 4 * 1 );
    long long ret0 = ft0.get();
    std::future<long long> ft1 = std::async(std::launch::async, m_add, v, MAX / 4 * 1, MAX / 4 * 2 );
    long long ret1 = ft1.get();
    std::future<long long> ft2 = std::async(std::launch::async, m_add, v, MAX / 4 * 2, MAX / 4 * 3 );
    long long ret2 = ft2.get();
    std::future<long long> ft3 = std::async(std::launch::async, m_add, v, MAX / 4 * 3, MAX);
    long long ret3 = ft3.get();

    std::cout << "Case B - parallel thread : " << ret0 + ret1 + ret2 + ret3 << std::endl;

    return 0;
}