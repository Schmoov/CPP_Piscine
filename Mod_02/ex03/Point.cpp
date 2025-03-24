#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

Point::Point() : x(0), y(0) {}
Point::Point(const Point& p) : x(p.x), y(p.y) {}
Point::Point(const float& nx, const float& ny) : x(nx), y(ny) {}
Point::~Point() {}
Point& Point::operator=(const Point& p)
{
	(void)p;
	std::cerr << "[WARNING]: Skill issue\n";
	return *this;
}

const Fixed& Point::getX() const
{
	return x;
}

const Fixed& Point::getY() const
{
	return y;
}
	
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed x1 = a.getX();
	Fixed y1 = a.getY();
	Fixed x2 = b.getX();
	Fixed y2 = b.getY();
	Fixed x3 = c.getX();
	Fixed y3 = c.getY();
	Fixed x = point.getX();
	Fixed y = point.getY();

	Fixed dotProd = (y2-y3)*(x1-x3) + (x3-x2)*(y1-y3);
	if (dotProd == Fixed(0))
		return false;
	Fixed v1 = ((y2-y3)*(x-x3) + (x3-x2)*(y-y3)) / dotProd;
	Fixed v2 = ((y3-y1)*(x-x3) + (x1-x3)*(y-y3)) / dotProd;
	Fixed v3 = Fixed(1) - v1 - v2;

	return (v1 > 0 && v2 > 0 && v1+v2 < 1);
}
