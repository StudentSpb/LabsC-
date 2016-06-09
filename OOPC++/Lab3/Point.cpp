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

Point& Point::operator+=(const Point& other)
{
	this->m_x += other.m_x;
	this->m_y += other.m_y;
	return *this;
}

Point& Point::operator+=(int other)
{
	this->m_x += other;
	this->m_y += other;
	return *this;
}

Point Point::operator+(int value)
{
	return Point(m_x+value, m_y +value);
}

Point Point::operator+(const Point& other)
{
	return Point(m_x + other.m_x, m_y + other.m_y);
}

Point operator+(int value, Point other)
{
	return Point(value + other.m_x, value + other.m_y);
}


Point Point::operator-(int value)
{
	return Point(m_x - value, m_y - value);
}

Point Point::operator-(const Point& other)
{
	return Point(m_x - other.m_x, m_y - other.m_y);
}

Point operator+(const Point& val)
{
	return val;
}

Point operator-(const Point& val)
{
	return Point(-val.m_x, -val.m_y);
}

Point& operator-=(Point& other1, const Point& other2)
{
	other1.m_x -= other2.m_x;
	other1.m_y -= other2.m_y;

	return other1;
}
Point& operator-=(Point& other1, int other2)
{
	other1.m_x -= other2;
	other1.m_y -= other2;
	return other1;
}
