#include "Point.hpp"
static int i = 0;

static bool	isSameSide(const Point a, const Point b, const Point c,
		const Point p)
{
	Fixed	cp1 = (b.getX() - a.getX()) * (p.getY() - a.getY())
		- (b.getY() - a.getY()) * (p.getX() - a.getX());

	Fixed	cp2 = (b.getX() - a.getX()) * (c.getY() - a.getY())
		- (b.getY() - a.getY()) * (c.getX() - a.getX());

	std::cout << "index " << i << std::endl;
	std::cout << cp1 << " ";
	std::cout << cp2 << std::endl;
	i++;
	return (Fixed((cp1 * cp2)) > Fixed(0));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	return (isSameSide(a, b, c, point) && isSameSide(b, c, a, point)
			&& isSameSide(c, a, b, point));
}
