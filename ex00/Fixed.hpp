/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:31:50 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/09 18:31:51 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed
{
public:
	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed& src);
	Fixed& operator=(const Fixed& src);
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int _value;
	static int const _fract_bits = 8;
};
