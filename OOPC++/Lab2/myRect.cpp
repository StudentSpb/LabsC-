#include "myRect.h"
#include <iostream>

Rect::Rect():Shape(Red)
{
	m_left = 0;
	m_right = 0;
	m_top = 0;
	m_bottom = 0;
}

Rect::Rect(float left, float right, float top, float bottom, Color color):Shape(color)
{
	m_left = left;
	m_right = right;
	m_top = top;
	m_bottom = bottom;
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

void Rect::InflateRect(float incrLeft, float incrRight, float incrTop, float incrBottom)
{
	m_left += incrLeft;
	m_right += incrRight;
	m_top += incrTop;
	m_bottom += incrBottom;
	normalize();
}

void Rect::InflateRect(float incrOne, float incrTwo)
{
	m_left += incrOne;
	m_right += incrTwo;
	normalize();
}

void Rect::SetAll(float left, float right, float top, float bottom)
{
	m_left = left;
	m_right = right;
	m_top = top;
	m_bottom = bottom;
	normalize();
}
void Rect::GetAll(float& left, float& right, float& top, float& bottom)  const
{
	left = m_left;
	right = m_right;
	top = m_top;
	bottom = m_bottom;
}

Rect::Rect(const Rect& other): Shape(other)
{
	m_left = other.m_left;
	m_right = other.m_right;
	m_top = other.m_top;
	m_bottom = other.m_bottom;
}

Rect BoundingRect(Rect r1, Rect r2)
{	
	float left1, right1, top1, bottom1;
	r1.GetAll(left1, right1, top1, bottom1);
	float left2, right2, top2, bottom2;
	r2.GetAll(left2, right2, top2, bottom2);

	float minl = (left1 > left2) ? left2 : left1;
	float maxr = (right1 > right2) ? right1 : right2;
	float mint = (top1 > top2) ? top2 : top1;
	float maxb = (bottom1 > bottom2) ? bottom2 : bottom1;
	return Rect(minl, maxr, mint, maxb, Red);
}

Rect BoundingRect2(const Rect& r1, const Rect& r2)
{
	float left1, right1, top1, bottom1;
	r1.GetAll(left1, right1, top1, bottom1);
	float left2, right2, top2, bottom2;
	r2.GetAll(left2, right2, top2, bottom2);

	float minl = (left1 > left2) ? left2 : left1;
	float maxr = (right1 > right2) ? right1 : right2;
	float mint = (top1 > top2) ? top2 : top1;
	float maxb = (bottom1 > bottom2) ? bottom2 : bottom1;
	return Rect(minl, maxr, mint, maxb, Blue);
}

Rect::~Rect()
{
	std::cout << "Now I am in Rect's destructor!" << "\n";
}

void Rect::WhereAmI()
{
	std::cout << "Now I am in class Rect" << "\n";

}

void Rect::Inflate(int inflate)
{
	m_bottom = m_bottom + static_cast<float>(inflate);
}
