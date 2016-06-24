#pragma once
#include "Shape.h"
#include <iostream>

class Rect :public Shape {
	int m_p1x;
	int m_p1y;
	int m_p2x;
	int m_p2y;
public:
	Rect();
	Rect(int p1x, int p1y, int p2x, int p2y, sColor c);
	virtual ~Rect();

	virtual double GetSquare() const;
	virtual Rect* clone() const;

	bool operator==(const Shape&);
	Rect& operator=(const Shape&);

	friend std::ofstream& operator<<(std::ofstream&, const Rect*);
	friend std::ostream& operator<<(std::ostream&, const Rect*);

	double remoteness() const;

	void normalize();	
	//void GetAll(int& p1x, int& p1y, int& p2x, int& p2y) const;
	//virtual	void WhereAmI()const;
	
	//virtual void Inflate(int i);
};
