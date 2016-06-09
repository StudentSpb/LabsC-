#pragma once
#include "Point.h"
#include <ostream>

class Circle
{
private:
	float m_diametr;
	Point m_point;

public:
	Circle(int x = 0, int y = 0, float diametr = 0);

	Circle(const Circle& other);
	Circle(Circle&& other);
	~Circle();

	Circle& operator = (const Circle& other);
	Circle& operator = (Circle&& other);
	bool operator ==(const Circle& other) const;

	float GetSquare() const;
	friend std::ostream & operator<<(std::ostream & os, const Circle & string);
	friend std::ofstream& operator<<(std::ofstream& ofs, const Circle& cir);
};
std::ostream & operator<<(std::ostream & os, const Circle & string);
std::ofstream& operator<<(std::ofstream& ofs, const Circle& cir);
