#include "Rect.h"
#include <fstream>

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


Rect::Rect(const Rect& other): Shape(other.GetColor()), m_left(other.m_left), m_right(other.m_right), m_top(other.m_top), m_bottom(other.m_bottom)
{

}

float Rect::GetSquare()
{
	float sqre = (m_right - m_left)*(m_bottom - m_top);
	return sqre;
}


Rect* Rect::Clone() const
{
	return new Rect(*this);
}

bool Rect::operator==(const Shape& other)
{ 
	if (const Rect* rec = dynamic_cast<const Rect*>(&other))
	{
		if (m_bottom == rec->m_bottom && m_left == rec->m_left && m_right == rec->m_right && m_top == rec->m_top && m_color == GetColor())
			return true;
	}
	return false;
}

Rect* Rect::operator=(const Shape& other)
{
	if (const Rect* rect = dynamic_cast<const Rect*>(&other))
	{
		m_color = rect->GetColor();
		m_bottom = rect->m_bottom;
		m_top = rect->m_top;
		m_left = rect->m_left;
		m_right = rect->m_right;
	}
	return this;
}

Rect* Rect::operator=(Shape&& other)
{
	if (const Rect* rect = dynamic_cast<const Rect*>(&other))
	{
		m_color = rect->GetColor();
		m_bottom = rect->m_bottom;
		m_top = rect->m_top;
		m_left = rect->m_left;
		m_right = rect->m_right;
	}
	return this;
}

Rect::~Rect()
{
	
}

std::ostream& operator<<(std::ostream& os, const Rect& string)
{
	//os << "Rectangle: " <<"Bottom-" << string.m_bottom << " Top-" << string.m_top << " Left-" << string.m_left << " Right-" << string.m_right << std::endl;
	os<< string.m_bottom<< " "<< string.m_top << " " << string.m_left << " " << string.m_right << std::endl;
	return os;
}

std::ofstream & operator<<(std::ofstream & ofs, const Rect & rec)
{
	ofs << "" << 1 << std::endl << rec.m_bottom << " " << rec.m_top << " " << rec.m_left << " " << rec.m_right << std::endl;
	return ofs;
}

