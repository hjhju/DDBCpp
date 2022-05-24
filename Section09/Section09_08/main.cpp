#include <iostream>

using namespace std;

/* Section09_08 형변환을 오버로딩 */

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	void setCents(int cents) { m_cents = cents; }

	operator int()
	{
		cout << "cast here" << endl;
		return m_cents;
	}
};

class Dollar
{
private:
	int m_dollars = 0;
public:
	Dollar(const int& input) : m_dollars(input) {}
	operator Cents()
	{
		return Cents(m_dollars * 100);
	}
};

void printInt(const int& value)
{
	cout << value << endl;
}

int main()
{
	Cents cents(7);

	// 모두 같은 표현
	int value = (int)cents;
	value = int(cents);
	value = static_cast<int>(cents);

	printInt(cents);

	Dollar dol(2);
	// dol 객체값을 cen에 대입하려는 행위
	// cen을 dol의 사본으로 만드는 행위와 같음
	// 둘의 자료형이 맞지 않으므로 dol을 복사한 사본값이 Cents로 형변환
	Cents cen = dol; 
	printInt(cen);

	return 0;
}