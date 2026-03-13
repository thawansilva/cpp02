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

	// Getters & Setters
	Fixed	getX(void) const;
	void	setX(Fixed& x);
	Fixed	getY(void) const;
	void	setY(Fixed& y);

private:
	Fixed const	x;
	Fixed const	y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
