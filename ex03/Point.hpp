#pragma once

#include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& src);
	Point&	operator=(const Point& src);
	~Point();

	// Getters
	const Fixed	getX(void) const;
	const Fixed	getY(void) const;

private:
	Fixed const	x;
	Fixed const	y;
};

bool			bsp(Point const a, Point const b, Point const c, Point const point);
std::ostream&	operator<<(std::ostream &output, const Point &src);
