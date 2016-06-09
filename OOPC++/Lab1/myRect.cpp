#include "myRect.h"

Rect::Rect()
{
	m_left = 0;
	m_right = 0;
	m_top = 0;
	m_bottom = 0;
}

Rect::Rect(int left, int right, int top, int bottom)
{
	m_left = left;
	m_right = right;
	m_top = top;
	m_bottom = bottom;
	normalize();
}

void Rect::normalize()
{
	int coor = 0;
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

void Rect::InflateRect(int incrLeft, int incrRight, int incrTop, int incrBottom)
{
	m_left += incrLeft;
	m_right += incrRight;
	m_top += incrTop;
	m_bottom += incrBottom;
	normalize();
}

void Rect::InflateRect(int incrOne, int incrTwo)
{
	m_left += incrOne;
	m_right += incrTwo;
	normalize();
}

void Rect::SetAll(int left, int right, int top, int bottom)
{
	m_left = left;
	m_right = right;
	m_top = top;
	m_bottom = bottom;
	normalize();
}
void Rect::GetAll(int& left, int& right, int& top, int& bottom)  const
{
	left = m_left;
	right = m_right;
	top = m_top;
	bottom = m_bottom;
}

Rect::Rect(const Rect& other)
{
	m_left = other.m_left;
	m_right = other.m_right;
	m_top = other.m_top;
	m_bottom = other.m_bottom;
}

Rect BoundingRect(Rect r1, Rect r2)
{	
	int left1, right1, top1, bottom1;
	r1.GetAll(left1, right1, top1, bottom1);
	int left2, right2, top2, bottom2;
	r2.GetAll(left2, right2, top2, bottom2);

	int minl = (left1 > left2) ? left2 : left1;
	int maxr = (right1 > right2) ? right1 : right2;
	int mint = (top1 > top2) ? top2 : top1;
	int maxb = (bottom1 > bottom2) ? bottom2 : bottom1;
	return Rect(minl, maxr, mint, maxb);
}

Rect BoundingRect2(const Rect& r1, const Rect& r2)
{
	int left1, right1, top1, bottom1;
	r1.GetAll(left1, right1, top1, bottom1);
	int left2, right2, top2, bottom2;
	r2.GetAll(left2, right2, top2, bottom2);

	int minl = (left1 > left2) ? left2 : left1;
	int maxr = (right1 > right2) ? right1 : right2;
	int mint = (top1 > top2) ? top2 : top1;
	int maxb = (bottom1 > bottom2) ? bottom2 : bottom1;
	return Rect(minl, maxr, mint, maxb);
}

Rect::~Rect()
{
	
}