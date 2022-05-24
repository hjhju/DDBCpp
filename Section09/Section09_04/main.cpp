#include <iostream>
#include <vector>
#include <random>
using namespace std;

/* Section09_04 �� ������ �����ε� */

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

	// sorting���� >�� ������
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

	// c++17������ std::random_shuffle�� ����
	// c++17 �̻� �����Ϸ������� �Ʒ��� ���� std::shuffle�� ����� �� ����
	// #include <random>
	// std::random_device rd;
	// std::mt19937 g(rd());
	// std::shuffle(arr.begin(), arr.end(), g);

	std::random_shuffle(begin(arr), end(arr));
	for (auto& e : arr)
		cout << e << " ";
	cout << endl;

	// operator < �� ������ �ȵǾ� ������ ũ�� �񱳸� ���Ѵٴ� ���� ��
	std::sort(begin(arr), end(arr)); 
	for (auto& e : arr)
		cout << e << " ";
	cout << endl;


	return 0;
}