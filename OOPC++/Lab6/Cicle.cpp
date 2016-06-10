#include  "Circle.h"


Circle::Circle(int x, int y,float diametr, Color color):Shape(color), m_diametr(diametr), m_x(x), m_y(y)
{
}

Circle::Circle(const Circle & other):Shape(other), m_diametr(other.m_diametr), m_x(other.m_x), m_y(other.m_y)
{
}

Circle::Circle(Circle && other):Shape(other), m_diametr(other.m_diametr), m_x(other.m_x), m_y(other.m_y)
{
	other.m_diametr = 0;
	other.m_x = 0;
	other.m_y = 0;
}


Circle::~Circle()
{
	
}

/*
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
*/

bool Circle::operator==(const Shape & other)
{
	if(const Circle* cir = dynamic_cast<const Circle*>(&other))
	{
		if (m_x == cir->m_x && m_y == cir->m_y && m_diametr == cir->m_diametr)
			return true;
	}
	return false;
}

float Circle::GetSquare()
{
	float sqre = m_diametr*m_diametr * 3.14 / 4;
	return sqre;
}

Circle* Circle::Clone() const
{
	return new Circle(*this);
}

std::ostream & operator<<(std::ostream & os, const Circle & string)
{
	os << "Cicle: " <<"Center-" << string.m_x << " " << string.m_y << " Diametr-" << string.m_diametr <<std::endl;
	return os;
}

std::ofstream& operator<<(std::ofstream& ofs, const Circle& cir)
{
	//ofs << "" << cir.m_x << " " << cir.m_y << " " << cir.m_diametr;
	return ofs;
}

