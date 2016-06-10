#pragma once
#include <ostream>

enum Color{Red, Blue, Green, White};

class Shape
{
private:
	Color m_color;

public:
	virtual ~Shape(){}

	Shape(Color color = White);

	virtual Shape* Clone() const =0;
	virtual float GetSquare() = 0;
	virtual bool operator ==(const Shape& other)=0;
	friend std::ostream & operator<<(std::ostream & os, const Shape & string);
};
std::ostream & operator<<(std::ostream & os, const Shape & string);