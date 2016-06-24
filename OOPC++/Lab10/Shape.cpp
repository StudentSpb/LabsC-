#include "Shape.h"
#include <iostream>


Shape::Shape() {
	m_color = BLACK;
	std::cout << "Shape default constructor ";
}

Shape::Shape(sColor c) {
	m_color = c;
	std::cout << "Shape constructor ";
}

Shape::~Shape() {
	std::cout << "Now I am in Shape's destructor!\n";
}

bool Shape::operator==(const Shape& other) {
	return (m_color == other.m_color);
}

Shape& Shape::operator=(const Shape& other) {
	m_color = other.m_color;
	return *this;
}

const Shape::sColor& Shape::GetColor() const {
	return m_color;
}

//std::ostream& operator<<(std::ostream& os, const Shape* s) {
//	return os;
//}

//void Shape::SetColor(sColor c) {
//	m_color = c;
//}

//void Shape::WhereAmI()const {
//	std::cout << "Now I am in class Shape\n";
//}

