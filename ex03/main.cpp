/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:33:01 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/09 20:59:14 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point	a;
	Point	b(0, 10);
	Point	c(10, 0);

	std::cout << "=== Triangulo ===" << std::endl;
	std::cout << "a(0,0) b(0, 10) c(10, 0)" << std::endl;
	std::cout << "=================" << std::endl;
	Point	inside(5,5);
	Point	outside(15, 15);
	Point	online(0,5);
	Point	vertix;
	std::cout << (bsp(a, b, c, inside) ? "It's inside": "Outside") << std::endl;
	std::cout << (bsp(a, b, c, outside) ? "It's inside": "Outside") << std::endl;
	std::cout << (bsp(a, b, c, online) ? "It's inside": "Outside") << std::endl;
	std::cout << (bsp(a, b, c, vertix) ? "It's inside": "Outside") << std::endl;
	return 0;
}
