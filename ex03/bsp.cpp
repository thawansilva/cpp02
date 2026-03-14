/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 18:24:17 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/14 15:16:03 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	getArea(const Point& a, const Point& b, const Point& c)
{
	Fixed area = ((a.getX() * (b.getY() - c.getY()))
			+ (b.getX() * (c.getY() - a.getY()))
			+ (c.getX() * (a.getY() - b.getY())));
	if (area < Fixed(0))
		area = area * Fixed(-1);
	return (area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed areaABC = getArea(a, b, c);
	Fixed areaABP = getArea(a, b, point);
	Fixed areaBCP = getArea(b, c, point);
	Fixed areaACP = getArea(a, c, point);

	if (areaABP == Fixed(0) || areaBCP == Fixed(0) || areaACP == Fixed(0))
		return (false);
	return (areaABC == (areaABP + areaBCP + areaACP));
}
