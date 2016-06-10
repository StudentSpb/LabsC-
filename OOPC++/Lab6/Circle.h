#pragma once
#include <ostream>
#include "Shape.h"

class Circle: public Shape
{
private:
	float m_diametr;
	int m_x;
	int m_y;
	//Point m_point;

public:
	explicit Circle(int x = 0, int y = 0, float diametr = 0, Color color = Red);

	Circle(const Circle& other);
	Circle(Circle&& other);
	~Circle();

	bool operator ==(const Shape& other);

	virtual float GetSquare() override;
	virtual Circle* Clone() const override;

	friend std::ostream & operator<<(std::ostream & os, const Circle & string);
	friend std::ofstream& operator<<(std::ofstream& ofs, const Circle& cir);
};
std::ostream & operator<<(std::ostream & os, const Circle & string);
std::ofstream& operator<<(std::ofstream& ofs, const Circle& cir);
