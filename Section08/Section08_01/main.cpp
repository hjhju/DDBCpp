#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Section08_01 ��ü���� ���α׷��ְ� Ŭ���� */
/* Section08_02 ĸ��ȭ, ���� ������, ���� �Լ� */

// Object
class Friend
{
public: // ���� ������ access specifier (public, private, protected)
	string m_name;
	string m_address;
	int age;
	double height;
	double weight;

	void print()
	{
		cout << m_name << " " << m_address << " " << age << " " << height << " " << weight << endl;
	}

};


class Date
{
//public:
//private:
	int m_month;
	int m_day;
	int m_year;

// private ��� �������� ���� Ŭ���� ���� ��� �Լ������� ������ ����
public: // access function

	/* const�� ��ġ�ʵ��� ������ �ɾ���
	   &�� ���۷����� �̰����� ���۷����� ���Ǿ����� ���������ʰ� �ٷ� �����Ͽ� ���� ����ϰ� ���� (parameter�� ���ڰ��� �����Ͽ� ���)
	   �����ϴ� ������带 ���ְ� �Ǽ������� ��ȭ�� ���ֱ� ���� const�� &�� ��� */

	// setters
	void setDate(const int& month_input, const int& day_input, const int& year_input)
	{
		m_month = month_input;
		m_day = day_input;
		m_year = year_input;
	}

	void setMonth(const int& month_input)
	{
		m_month = month_input;
	}

	void setYear(const int& year_input)
	{
		m_year = year_input;
	}
	
	// getters
	int &getDay()
	{
		return m_day;
	}

	int& getMonth()
	{
		return m_month;
	}

	int& getYear()
	{
		return m_year;
	}

	// Date Ÿ���� '��ü'�� �Ķ���ͷ� �޴´ٴ� ���� �ǹ�
	void copyFrom(const Date& original)
	{
		m_month = original.m_month;
		m_day = original.m_day;
		m_year = original.m_year;
	}
};

int main()
{
	Friend jj{ "jakc jack", "uptown", 2, 173.2, 60.3 }; //instanciation, instance
	jj.print();

	vector<Friend> my_friends;
	my_friends.resize(2);

	// my_friends[0].print();

	//Date today{ 8, 4, 2025 };
	// ���� �����ڰ� ����Ǿ� ���� ������ �Ʒ��ڵ�� ����, private�� �⺻�̱⶧��
	//today.m_month = 9;
	Date today2;
	today2.setDate(8, 4, 2025);
	today2.setMonth(10);

	cout <<&today2<< " " << today2.getDay() << endl;

	Date copy;
	copy.copyFrom(today2);
	cout << &copy<< " " << copy.getDay() << endl;


	return 0;
}