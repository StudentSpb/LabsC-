#include "Shape.h"
#include <fstream>


Shape::Shape(Color color)
{
	m_color = color;
}

Color Shape::GetColor() const
{
	return m_color;
}

std::ostream& operator<<(std::ostream& os, const Shape& string)
{
	os << string.m_color;
	return os;
}

std::ofstream& operator<<(std::ofstream& ofs, const Shape& shape)
{
	switch(shape.m_color)
	{
	case Blue:
		ofs << 1;
		break;
	case Green:
		ofs << 2;
		break;
	case Red:
		ofs << 0;
		break;
	case White:
		ofs << 3;
		break;
	}
	return ofs;
}

