#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Section08_01 객체지향 프로그래밍과 클래스 */
/* Section08_02 캡슐화, 접근 지정자, 접근 함수 */

// Object
class Friend
{
public: // 접근 지정자 access specifier (public, private, protected)
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

// private 멤버 변수들은 같은 클래스 내의 멤버 함수에서는 접근이 가능
public: // access function

	/* const는 변치않도록 제약을 걸어줌
	   &는 레퍼런스로 이곳에서 레퍼런스로 사용되었으며 복사하지않고 바로 접근하여 값을 사용하게 해줌 (parameter에 인자값을 복사하여 사용)
	   복사하는 오버헤드를 없애고 실수로인한 변화를 없애기 위해 const와 &를 사용 */

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

	// Date 타입의 '객체'를 파라미터로 받는다는 것을 의미
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
	// 접근 지정자가 선언되어 있지 않으면 아래코드는 에러, private가 기본이기때문
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