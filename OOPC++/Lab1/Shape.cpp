#include "Shape.h"
#include <iostream>

Shape::Shape()
{
	m_color = White;
}

Shape::Shape(Color color)
{
	m_color = color;
}


Shape::~Shape()
{
	std::cout << "Now I am in Shape's destructor!" << "\n";
}

void Shape::WhereAmI()
{
	std::cout << "Now I am in class Shape" << "\n";

}

void Shape::Inflate(int a)
{
	
}



