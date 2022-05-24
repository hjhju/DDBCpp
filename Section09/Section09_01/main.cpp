#include <iostream>

using namespace std;

/* Section09_01 ��� ������ �����ε� */

// ������ �����ε� 
// 1) �����Լ��� ������ �����ε�
//   - Cents add(const Cents& c1, const Cents& c2) ����
// 
// 2) ����Լ��� ������ �����ε� : ����Լ��� ��ü���� ȣ���Ҽ� �ִ� �Լ�
//   - Cents operator + (const Cents& c2)


class Cents
{
private:
	int m_cents;
public:
	Cents(int cents=0) { m_cents = cents; }

	// const ��ü�� const �� �ڿ� ���� ��� �Լ��� ȣ���� �� ����
	int getCents() const { return m_cents; }

	int &getCents() { return m_cents; }

	//friend Cents operator + (const Cents& c1, const Cents& c2)
	//{
	//	return Cents(c1.getCents() + c2.getCents());
	//}


	// friend�� ���� �Ű������� �ʹ� ���ٴ� ������ ��
	// �Ʒ�ó�� this Ȱ��
	// ����Լ��� ȣ���� ������� c1�� ù��° �ǿ����� ��, c2�� �Ķ���ͷ� �Ѿ�� �ι�° �ǿ����ڷ� ����

	// ������ �߿��� =, [], (), -> �� ��� �Լ��θ� �����ε� ����!!
	Cents operator + (const Cents& c2)
	{
		return Cents(this->m_cents + c2.m_cents);
	}
		
};

// c_out�� �ٲ�� ���̹Ƿ� const�� �Ǹ� �ȵ�
// c_out�� ��� �޸��� ���� �ٲ��� �ϹǷ� L-value�� �ۿ�
// �̿� ���� int& �Լ� ȣ��
void add(const Cents& c1, const Cents& c2, Cents& c_out)
{
	c_out.getCents() = c1.getCents() + c2.getCents();
}

Cents add(const Cents& c1, const Cents& c2)
{
	return Cents( c1.getCents() + c2.getCents());
}


int main()
{
	Cents cents1(6);
	Cents cents2(8);

	Cents sum;
	add(cents1, cents2, sum);

	cout << sum.getCents() << endl;

	cout << add(cents1, cents2).getCents() << endl;

	// �͸� object ��� ����
	cout << (cents1 + cents2 + Cents(6) + Cents(10)).getCents() << endl;


	return 0;
}