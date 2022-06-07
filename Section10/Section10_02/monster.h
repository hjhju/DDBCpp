#pragma once

#include <string>
#include "position2D.h"

class Monster
{
private:
	std::string m_name;
	//int m_x; // location
	//int m_y; 
	position2D m_location; // moster�� position�� ����ϴ� ���� ���� ������ ��

public:
	//Monster(const std::string name_in, const int& x_in, const int& y_in)
	Monster(const std::string name_in, const position2D & pos_in)
		: m_name(name_in), m_location(pos_in)
	{}

	void moveTo(const position2D& pos_target)
	{
		//m_x = x_target;
		//m_y = y_target;
		m_location.set(pos_target);
	}

	friend std::ostream & operator << (std::ostream& out, const Monster& monster)
	{
		out << monster.m_name << " " << monster.m_location;
		return out;
	}
};