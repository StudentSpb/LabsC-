#include "Rect.h"
#include <iostream>

Rect::Rect() :Shape() {
	m_p1x = 0;
	m_p1y = 0;
	m_p2x = 0;
	m_p2y = 0;
	std::cout << "Rect default constructor ";
};
Rect::Rect(int p1x, int p1y, int p2x, int p2y, sColor c) :Shape(c) {
	m_p1x = p1x;
	m_p1y = p1y;
	m_p2x = p2x;
	m_p2y = p2y;
	normalize();
	std::cout << "Rect constructor with params ";
}

Rect::~Rect() {
	std::cout << "Now I am in Rect's destructor!\n";
}

double Rect::GetSquare() const {
	return (m_p2x - m_p1x) * (m_p2y - m_p1y);
}

Rect* Rect::clone() const {
	return new Rect(*this);
}

bool Rect::operator==(const Shape& other) {
	if (const Rect* pRec = dynamic_cast<const Rect*>(&other)) {
		return (m_p1x == pRec->m_p1x &&
				m_p2x == pRec->m_p2x &&
				m_p1y == pRec->m_p1y &&
				m_p2y == pRec->m_p2y &&
				Shape::operator==(other));
	}
	else { return false; };
}

Rect& Rect::operator=(const Shape& other) {
	if (const Rect* pRec = dynamic_cast<const Rect*>(&other)) {
		m_p1x = pRec->m_p1x;
		m_p2x = pRec->m_p2x;
		m_p1y = pRec->m_p1y;
		m_p2y = pRec->m_p2y;
		Shape::operator=(other);
		return *this;
	}
	else { throw "Different classes"; };
}

//void Rect::WhereAmI()const {
//	std::cout << "Now I am in class Rect\n";
//}
//
//void Rect::GetAll(int& p1x, int& p1y, int& p2x, int& p2y) const {
//	p1x = m_p1x;
//	p1y = m_p1y;
//	p2x = m_p2x;
//	p2y = m_p2y;
//}

double Rect::remoteness() const {
	int xC = ((m_p2x - m_p1x) / 2) + m_p1x;
	int yC = ((m_p2y - m_p1y) / 2) + m_p1y;
	double rmt = sqrt(xC * xC + yC * yC);
	std::cout << rmt << " - ";
	return rmt;
}

void Rect::normalize() {
	int tmp;
	if (m_p1x > m_p2x) {
		tmp = m_p1x;
		m_p1x = m_p2x;
		m_p2x = tmp;
	}
	if (m_p1y > m_p2y) {
		tmp = m_p1y;
		m_p1y = m_p2y;
		m_p2y = tmp;
	}
}

std::ofstream& operator<<(std::ofstream& ofs, const Rect* r) {
	ofs << std::left << std::setw(2) << r->m_p1x << " " << std::setw(2) << r->m_p1y << " "
		<< std::setw(2) << r->m_p2x << " " << std::setw(2) << r->m_p2y << " " << std::setw(2) << r->m_color;
	return ofs;
}

std::ostream& operator<<(std::ostream& os, const Rect* r) {
	os << std::left << std::setw(2) << r->m_p1x << " " << std::setw(2) << r->m_p1y << " " 
		<< std::setw(2) << r->m_p2x << " " << std::setw(2) << r->m_p2y << " " << std::setw(7) << r->m_color;//col[r->Shape::m_color];
	return os;
}



//void Rect::Inflate(int i) {
//	m_p1x = m_p1x - i;
//	m_p1y = m_p1y - i;
//	m_p2x = m_p2x + i;
//	m_p2y = m_p2y + i;
//	std::cout << "Rect inflate\n";
//}






//Rect::Rect(const Rect & other) {
//	m_left = other.m_left;
//	m_right = other.m_right;
//	m_top = other.m_top;
//	m_bottom = other.m_bottom;
//
//	std::cout << "Copy constructor\n";
//}
//
//void Rect::InflateRect(int l_tInf, int r_bInf){
//	m_left = m_left - l_tInf;
//	m_right = m_right + r_bInf;
//	m_top = m_top - l_tInf;
//	m_bottom = m_bottom + r_bInf;
//
//	normalize();
//};
//
//void Rect::SetAll(int l, int r, int t, int b) {
//	m_left = l;
//	m_right = r;
//	m_top = t;
//	m_bottom = b;
//
//	normalize();
//}

//Rect BoundingRect(Rect r1, Rect r2) {
//	int r1_left, r1_right, r1_top, r1_bottom;
//	int r2_left, r2_right, r2_top, r2_bottom;
//
//	r1.GetAll(r1_left, r1_right, r1_top, r1_bottom);
//	r2.GetAll(r2_left, r2_right, r2_top, r2_bottom);
//
//	return Rect(r1_left < r2_left ? r1_left : r2_left,
//		r1_right < r2_right ? r2_right : r1_right,
//		r1_top < r2_top ? r1_top : r2_top,
//		r1_bottom < r2_bottom ? r2_bottom : r1_bottom);
//}
//
//Rect BoundingRect2(Rect & r1, Rect & r2) {
//	int r1_left, r1_right, r1_top, r1_bottom;
//	int r2_left, r2_right, r2_top, r2_bottom;
//
//
//	r1.GetAll(r1_left, r1_right, r1_top, r1_bottom);
//	r2.GetAll(r2_left, r2_right, r2_top, r2_bottom);
//
//	return Rect(r1_left < r2_left ? r1_left : r2_left,
//		r1_right < r2_right ? r2_right : r1_right,
//		r1_top < r2_top ? r1_top : r2_top,
//		r1_bottom < r2_bottom ? r2_bottom : r1_bottom);
//}