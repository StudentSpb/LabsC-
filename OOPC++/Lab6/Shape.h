#pragma once
#include <ostream>

enum Color{Red, Blue, Green, White};

class Shape
{
protected:
	Color m_color;

public:
	virtual ~Shape(){}

	Shape(Color color = White);

	Color GetColor() const;
	virtual Shape* Clone() const =0;
	virtual float GetSquare() = 0;
	virtual bool operator ==(const Shape& other) = 0 { return m_color == other.m_color; }
	virtual Shape* operator = (const Shape& other)=0;
	virtual Shape* operator = (Shape&& other)=0;

	friend std::ostream & operator<<(std::ostream & os, const Shape & string);
	friend std::ofstream& operator<<(std::ofstream& ofs, const Shape& cir);
};