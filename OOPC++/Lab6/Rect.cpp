#include "Rect.h"

Rect::Rect(float left, float right, float top, float bottom, Color color):Shape(color),m_left(left), m_right(right), m_top(top), m_bottom(bottom)
{
	normalize();
}

void Rect::normalize()
{
	float coor;
	if (m_left >= m_right)
	{
		coor = m_left;
		m_left = m_right;
		m_right = coor;
	}
	if (m_top >= m_bottom)
	{
		coor = m_top;
		m_top = m_bottom;
		m_bottom = coor;
	}
}


Rect::Rect(const Rect& other): Shape(other), m_left(other.m_left), m_right(other.m_right), m_top(other.m_top), m_bottom(other.m_bottom)
{

}

float Rect::GetSquare()
{
	return (m_right - m_left)*(m_bottom - m_top);
}


Rect* Rect::Clone() const
{
	return new Rect(*this);
}

bool Rect::operator==(const Shape& other)
{ 
	if (const Rect* rec = dynamic_cast<const Rect*>(&other))
	{
		if (m_bottom == rec->m_bottom && m_left == rec->m_left && m_right == rec->m_right && m_top == rec->m_top)
			return true;
	}

	return false;
}

Rect::~Rect()
{
	
}

std::ostream& operator<<(std::ostream& os, const Rect& string)
{
	os << "Rectangle: " <<"Bottom-" << string.m_bottom << " Top-" << string.m_top << " Left-" << string.m_left << " Right-" << string.m_right << std::endl;
	return os;
}

std::ofstream& operator<<(std::ofstream& ofs, const Rect& cir)
{
	return ofs;
}
