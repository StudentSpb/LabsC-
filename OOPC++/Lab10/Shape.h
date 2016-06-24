#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <fstream>

const char* const col[] = { "RED", "GREEN", "BLUE", "YELLOW", "BLACK", "WHITE" };

class Shape {
public:
	enum sColor { RED, GREEN, BLUE, YELLOW, BLACK, WHITE };
protected:
	sColor m_color;
public:
	Shape();
	Shape(sColor c);
	virtual ~Shape();

	virtual double GetSquare() const = 0;
	virtual Shape* clone() const = 0;
	const sColor& GetColor() const;

	virtual bool operator==(const Shape&);
	virtual Shape& operator=(const Shape&);

	//friend std::ostream& operator<<(std::ostream&, const Shape*);

	//void SetColor(sColor c);
	//virtual void Inflate(int i) = 0;
	//
	//virtual void WhereAmI()const;
	
	//virtual void Inflate(int i) = 0;
};
