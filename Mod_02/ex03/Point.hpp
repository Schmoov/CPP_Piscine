#pragma once
#include "Fixed.hpp"

class Point {
private:
	const Fixed x;
	const Fixed y;
public:
	Point();
	Point(const Point& a);
	Point(const float& nx, const float& ny);
	~Point();
	Point& operator=(const Point& t);
};

bool bsp(Point const a, Point const , Point const c, Point const point);
