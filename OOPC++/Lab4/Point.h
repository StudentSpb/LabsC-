#pragma once
#include <fstream>

class Point
{
private:
	int m_x;
	int m_y;
public:
	Point();
	Point(int x, int y);

	Point(const Point& point);
	Point(Point&& point);

	Point& operator=(const Point& other);
	Point& operator=(Point&& other);
	bool operator==(const Point&) const;

	friend std::ostream& operator<<(std::ostream&, const Point&);
	friend std::ofstream& operator<<(std::ofstream& ofs, const Point& p);
};
