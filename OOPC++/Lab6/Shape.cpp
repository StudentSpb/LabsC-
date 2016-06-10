#include "Shape.h"
#include <iostream>
#include "Rect.h"


Shape::Shape(Color color)
{
	m_color = color;
}


std::ostream& operator<<(std::ostream& os, const Shape& string)
{
	switch(string.m_color)
	{
	case Blue:
		os << "Color: Blue ";
		break;
	case Green:
		os << "Color: Green ";
		break;
	case Red:
		os << "Color: Red ";
		break;
	case White:
		os << "Color: White ";
		break;
	}
	return os;
}
