#pragma once
#include "Shape.h"


class Rect: public Shape
{
private: int m_left;
		 int m_right;
		 int m_top; 
		 int m_bottom;

private:
	void normalize();

public:
	Rect(int left, int right, int top, int bottom);
	void InflateRect(int incrLeft, int incrRight, int incrTop, int incrBottom);
	void InflateRect(int incrOne = 1, int incrTwo = 1);
	void SetAll(int left, int right, int top, int bottom);
	void GetAll(int& left, int& right, int& top, int& bottom) const;

	Rect();
	Rect(const Rect& other);
	~Rect();
	
};

Rect BoundingRect(Rect, Rect);
Rect BoundingRect2(const Rect&, const Rect&);