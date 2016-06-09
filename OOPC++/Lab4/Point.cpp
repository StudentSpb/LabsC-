#include "Point.h"

Point::Point()
{
	m_x = 1;
	m_y = 2;
}

Point::Point(int x, int y)
{
	m_x = x;
	m_y = y;
}

Point::Point(const Point & point)
{
	m_x = point.m_x;
	m_y = point.m_y;
}

Point::Point(Point && point)
{
	m_x = point.m_x;
	m_y = point.m_y;
}

Point & Point::operator=(const Point & other)
{
	m_x = other.m_x;
	m_y = other.m_y;
	return *this;
}

Point & Point::operator=(Point && other)
{
	m_x = other.m_x;
	other.m_x = 0;
	m_y = other.m_y;
	other.m_y = 0;
	return *this;
}

bool Point::operator==(const Point& tmp) const 
{
	if (m_x == tmp.m_x && m_y == tmp.m_y) return true;
	else return false;
}

std::ostream& operator<<(std::ostream& os, const Point& p) 
{
	os << "Point: "<< p.m_x << ", " << p.m_y;
	return os;
}

std::ofstream& operator<<(std::ofstream& ofs, const Point& p) 
{
	ofs << "" << p.m_x << " " << p.m_y;
	return ofs;
}


