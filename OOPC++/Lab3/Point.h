#pragma once

class Point
{
private:
	int m_x;
	int m_y;
public:
	Point();
	Point(int x, int y);

	Point& operator+=(const Point& other);
	Point& operator+=(int other);
	
	Point operator+(int value);
	Point operator+(const Point& other);
	friend Point operator+(int, Point);
	friend Point operator+(const Point& val);
	friend Point operator-(const Point& val);
	friend Point& operator-=(Point& other1, const Point& other2);
	friend Point& operator-=(Point& other1, int other2);

	Point operator-(int value);
	Point operator-(const Point& other);
};

Point operator+(int, Point);
Point operator+(const Point& val);
Point operator-(const Point& val);

Point operator-=(const Point& other1, const Point& other2);
Point operator-=(int other1, const Point& other2);