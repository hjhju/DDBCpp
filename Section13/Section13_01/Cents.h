#pragma once

class Cents
{
private:
	int m_Cents;
public:
	Cents(int cents) : m_Cents(cents)
	{

	}

	friend bool operator > (const Cents& c1, const Cents& c2)
	{
		return (c1.m_Cents > c2.m_Cents);
	}


	friend std::ostream& operator << (std::ostream &out, const Cents& cents)
	{
		out << cents.m_Cents << std::endl;
		return out;
	}
};