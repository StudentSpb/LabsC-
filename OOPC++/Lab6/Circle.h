#pragma once
#include <ostream>
#include "Shape.h"

class Circle: public Shape
{
private:
	float m_diametr;
	int m_x;
	int m_y;

public:
	 explicit Circle(int x = 0, int y = 0, float diametr = 15, Color color = Red);

	Circle(const Circle& other);
	Circle(Circle&& other);
	~Circle();

	virtual Circle* operator = (const Shape& other) override;
	virtual Circle* operator = (Shape&& other) override;
	bool operator ==(const Shape& other) override;

	virtual float GetSquare() override;
	virtual Circle* Clone() const override;

	friend std::ostream & operator<<(std::ostream & os, const Circle & string);
	friend std::ofstream& operator<<(std::ofstream& ofs, const Circle& cir);
};
//std::ostream & operator<<(std::ostream & os, const Circle & string);
//std::ofstream& operator<<(std::ofstream& ofs, const Circle& cir);