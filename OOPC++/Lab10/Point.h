#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>

//using namespace std;

class Point {
	int m_x;
	int m_y;
public:
	Point(int x = 0, int y = 0) : m_x(x), m_y(y) {};
	Point(const Point&);
	Point(Point&&);

	Point& operator=(const Point&);
	Point& operator=(Point&&);

	Point& operator+=(int);
	bool operator==(const Point&) const;
	bool operator<(const Point&) const;

	~Point() {};
	
	friend class pred;

	friend bool neg(const Point&);

	friend std::ostream& operator<<(std::ostream&, const Point&);
	friend std::ostream& operator<<(std::ostream&, const Point*);
	friend std::ofstream& operator<<(std::ofstream& ofs, const Point& p);
};
