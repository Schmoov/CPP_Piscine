#pragma once
#include "Fixed.hpp"

class Point {
private:
	const Fixed x;
	const Fixed y;
public:
	Point();
	Point(const Point& p);
	Point(const float& nx, const float& ny);
	~Point();
	Point& operator=(const Point& p);
	const Fixed& getX() const;
	const Fixed& getY() const;
};

bool bsp(Point const a, Point const , Point const c, Point const point);
