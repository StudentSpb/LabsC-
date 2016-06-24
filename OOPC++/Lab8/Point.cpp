#include "Point.h"

Point::Point(const Point& tmp) {
	m_x = tmp.m_x;
	m_y = tmp.m_y;
}

Point::Point(Point&& tmp) {
	m_x = tmp.m_x;
	tmp.m_x = 0;
	m_y = tmp.m_y;
	tmp.m_y = 0;
}

Point& Point::operator=(const Point& tmp) {
	if (this != &tmp)
	{
		m_x = tmp.m_x;
		m_y = tmp.m_y;
	}
	return *this;
}

Point& Point::operator=(Point&& tmp) {
	if (this != &tmp)
	{
		m_x = tmp.m_x;
		tmp.m_x = 0;
		m_y = tmp.m_y;
		tmp.m_y = 0;
	}
	return *this;
}

bool Point::operator==(const Point& tmp) const {
	if (m_x == tmp.m_x && m_y == tmp.m_y) return true;
	else return false;
}

bool Point::operator<(const Point& tmp) const {
	if (m_x < tmp.m_x && m_y < tmp.m_y) return true;
	else return false;
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
	os << "Center: (" << p.m_x << ", " << p.m_y << "), ";
	return os;
}

std::ostream& operator<<(std::ostream& os, const Point* p) {
	os << "Center: (" << p->m_x << ", " << p->m_y << "), ";
	return os;
}
std::ofstream& operator<<(std::ofstream& ofs, const Point& p) {
	ofs << "" << p.m_x << " " << p.m_y;
	return ofs;
}
