#pragma once
#include  "Shape.h"
#include  "myRect.h"

class Circle: public Shape
{
private:
	float m_diametr;
	float m_x;
	float m_y;

public:
	Circle();
	Circle(int x, int y, float diametr, Color color);
	Circle(const Rect&);

	~Circle();

	void WhereAmI();
	void Inflate(int);
};
