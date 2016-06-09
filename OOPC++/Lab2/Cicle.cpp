#include  "Circle.h"
#include <iostream>

Circle::Circle():Shape(Green)
{
	m_diametr = 15.5;
	m_x = 1;
	m_y = 2;
}

Circle::Circle(int x, int y,float diametr, Color color):Shape(color)
{
	m_diametr = diametr;
	m_x = static_cast<float> (x);
	m_y = static_cast<float> (y);
}

Circle::Circle(const Rect& rect):Shape(rect) //“ут берем базовую часть у Rect и передаем ее в Circle
{
	float top, bottom, left, right;
	rect.GetAll(left, right, top, bottom);
	m_diametr = bottom - top;
	m_x = (left + right)/2;
	m_y = (bottom + top)/2;
}


Circle::~Circle()
{
	std::cout << "Now I am in Circle's destructor!" << "\n";
}

void Circle::WhereAmI()
{
	std::cout <<  "Now I am in class Circle" << "\n";
}

void Circle::Inflate(int val)
{
	m_diametr = m_diametr + static_cast<float> (val);
}

