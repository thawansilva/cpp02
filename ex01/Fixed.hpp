/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:29:08 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/14 15:50:07 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed(void);
	Fixed(int const num_i);
	Fixed(float const num_f);
	Fixed(const Fixed& src);
	Fixed&	operator=(const Fixed& src);
	~Fixed(void);
	
	int				getRawBits(void) const;
	void			setRawBits(int const raw);
	float			toFloat(void) const;
	int				toInt(void) const;

private:
	int					_rawBits;
	static int const	_fractionalBits = 8;
};

std::ostream&	operator<<(std::ostream &output, const Fixed& src);
