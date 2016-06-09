#pragma once

enum Color{Red, Blue, Green, White};

class Shape
{
private:
	Color m_color;

public:
	Shape();
	Shape(Color color);

	virtual ~Shape();

	virtual void WhereAmI();
	virtual void Inflate(int);// = 0;
};