#include  "Circle.h"
#include <iostream>
#include <math.h>


Circle::Circle(int x, int y,float diametr):m_point(x,y), m_diametr(diametr)
{
}

Circle::Circle(const Circle & other):m_point(other.m_point), m_diametr(other.m_diametr)
{
}

Circle::Circle(Circle && other):m_diametr(other.m_diametr), m_point(std::move(other.m_point))
{
	other.m_diametr = 0;
}


Circle::~Circle()
{
	
}

Circle & Circle::operator=(const Circle & other)
{
	m_diametr = other.m_diametr;
	m_point = other.m_point;
	return *this;
}

Circle & Circle::operator=(Circle && other)
{
	m_diametr = other.m_diametr;
	other.m_diametr = 0;
	m_point = std::move(other.m_point);
	return *this;
}

bool Circle::operator==(const Circle & other) const
{
	if(m_point == other.m_point && m_diametr==other.m_diametr)
			return true;

	return false;
}

float Circle::GetSquare() const
{
	return (3,14 * pow(m_diametr,2))/4;
}

std::ostream & operator<<(std::ostream & os, const Circle & string)
{
	os << "Center: "<< string.m_point << " Diametr:" << string.m_diametr <<std::endl;
	return os;
}

std::ofstream& operator<<(std::ofstream& ofs, const Circle& cir)
{
	ofs << cir.m_point << " " << cir.m_diametr;
	return ofs;
}

