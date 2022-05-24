#include <iostream>
#include <vector>
#include <random>
using namespace std;

/* Section09_04 비교 연산자 오버로딩 */

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	friend std::ostream& operator << (std::ostream& out, const Cents& cents)
	{
		out << cents.m_cents;
		return out;
	}

	friend bool operator == (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents == c2.m_cents;
	}

	// sorting에서 >면 에러뜸
	friend bool operator < (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents < c2.m_cents;
	}

};

int main()
{
	Cents cents1(6), cents2(8);

	if (cents1 == cents2)
	{
		cout << "equal" << endl;
	}
	else
	{
		cout << "Not equal" << endl;
	}

	vector<Cents> arr(20);
	for (unsigned i = 0; i < 20; ++i)
	{
		arr[i].getCents() = i;
	}

	// c++17에서는 std::random_shuffle이 폐기됨
	// c++17 이상 컴파일러에서는 아래와 같이 std::shuffle을 사용할 수 있음
	// #include <random>
	// std::random_device rd;
	// std::mt19937 g(rd());
	// std::shuffle(arr.begin(), arr.end(), g);

	std::random_shuffle(begin(arr), end(arr));
	for (auto& e : arr)
		cout << e << " ";
	cout << endl;

	// operator < 이 구현이 안되어 있으면 크기 비교를 못한다는 에러 뜸
	std::sort(begin(arr), end(arr)); 
	for (auto& e : arr)
		cout << e << " ";
	cout << endl;


	return 0;
}