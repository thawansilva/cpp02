#include "Point.hpp"

Point::Point(): x(0), y(0) {}

Point::~Point() {}

Point::Point(const float x, const float y): x(x), y(y) {}

Point::Point(const Point& src): x(src.x), y(src.y) {}

Point&	Point::operator=(const Point& src)
{
	(void) src;
	return (*this);
}

Fixed	Point::getX(void) const
{
	return (this->x);
}

Fixed	Point::getY(void) const
{
	return (this->y);
}
