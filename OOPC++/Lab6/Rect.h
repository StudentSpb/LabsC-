#pragma once
#include "Shape.h"
#include <ostream>

class Rect : public Shape
{
private:
	float m_left;
	float m_right;
	float m_top;
	float m_bottom;

	void normalize();

public:
	explicit Rect(float left = 0, float right = 0, float top = 0, float bottom = 0, Color color = White);
	Rect(const Rect& other);

	virtual float GetSquare();
	virtual Rect* Clone() const override;
	virtual bool operator ==(const Shape& other);

	~Rect();

	friend std::ostream & operator<<(std::ostream & os, const Rect & string);
	friend std::ofstream& operator<<(std::ofstream& ofs, const Rect& cir);

};
std::ostream & operator<<(std::ostream & os, const Rect & string);
std::ofstream& operator<<(std::ofstream& ofs, const Rect& cir);
