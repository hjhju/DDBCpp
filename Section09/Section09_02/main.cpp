#include <iostream>
#include <fstream> // file �����

using namespace std;

/* Section09_02 ����� ������ �����ε� */

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

	// ù��° �Ķ���Ͱ� out�̶� ����Լ��� ���� �� ����
	friend std::ostream& operator << (std::ostream& out, const Point& point)
	{
		out << "(" << point.m_x << " " << point.m_y << " " << point.m_z << ")";
		
		return out;
	}

	// �Է� �����Ƿ� const�� ����
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