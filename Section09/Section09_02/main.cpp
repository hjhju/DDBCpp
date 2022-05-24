#include <iostream>
#include <fstream> // file 입출력

using namespace std;

/* Section09_02 입출력 연산자 오버로딩 */

class Point
{
private:
	double m_x, m_y, m_z;

public:
	Point(double x = 0.0, double y = 0.0, double z=0.0) : m_x(x), m_y(y), m_z(z)
	{}

	double getX() { return m_x; }
	double getY() { return m_y; }
	double getZ() { return m_z; }

	void print()
	{
		cout << m_x << " " << m_y << " " << m_z << endl;
	}

	// 첫번째 파라미터가 out이라 멤버함수로 만들 수 없음
	friend std::ostream& operator << (std::ostream& out, const Point& point)
	{
		out << "(" << point.m_x << " " << point.m_y << " " << point.m_z << ")";
		
		return out;
	}

	// 입력 받으므로 const는 제거
	friend std::istream& operator >> (std::istream& in, Point& point)
	{
		in >> point.m_x >> point.m_y >> point.m_z;

		return in;
	}
};


int main()
{
	ofstream of("out.txt");

	Point p1(0.0, 0.1, 0.2), p2(3.4, 1.5, 2.0);

	p1.print();
	p2.print();

	cout << p1 << " " << p2 << endl;
	of << p1 << " " << p2 << endl;


	Point p3, p4;

	cin >> p3 >> p4;
	cout << p3 << " " << p4 << endl;
	of << p3 << " " << p4 << endl;

	of.close();

	return 0;
}