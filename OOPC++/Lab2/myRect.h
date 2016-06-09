#pragma once
#include "Shape.h"

class Rect: public Shape
{
private: float m_left;
		 float m_right;
		 float m_top; 
		 float m_bottom;

private:
	void normalize();

public:
	Rect();
	Rect(float left, float right, float top, float bottom, Color color);
	void InflateRect(float incrLeft, float incrRight, float incrTop, float incrBottom);
	void InflateRect(float incrOne = 1, float incrTwo = 1);
	void SetAll(float left, float right, float top, float bottom);
	void GetAll(float& left, float& right, float& top, float& bottom) const;

	Rect(const Rect& other);
	~Rect();

	void WhereAmI();
	void Inflate(int a);
	
};

Rect BoundingRect(Rect, Rect);
Rect BoundingRect2(const Rect&, const Rect&);