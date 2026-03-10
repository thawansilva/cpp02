/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:32:53 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/09 21:26:34 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(int const num_i);
	Fixed(float const num_f);
	Fixed(const Fixed& src);
	Fixed& operator=(const Fixed& src);
	~Fixed();

	// Getters and Setters
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	// Functional members
	float			toFloat(void) const;
	int				toInt(void) const;
	static Fixed&	min(Fixed& num1, Fixed& num2);
	static Fixed&	max(Fixed& num1, Fixed& num2);
	static const Fixed&	min(const Fixed& num1, const Fixed& num2);
	static const Fixed&	max(const Fixed& num1, const Fixed& num2);
	bool			operator>(const Fixed& src) const;
	bool			operator<(const Fixed& src) const;
	bool			operator>=(const Fixed& src) const;
	bool			operator<=(const Fixed& src) const;
	bool			operator==(const Fixed& src) const;
	bool			operator!=(const Fixed& src) const;
	int				operator+(const Fixed& src) const;
	int				operator-(const Fixed& src) const;
	float			operator*(const Fixed src) const;
	float			operator/(const Fixed& src) const;
	Fixed			operator++(int);
	Fixed			operator--(int);
	Fixed&			operator++();
	Fixed&			operator--();

private:
	int					_rawBits;
	static int const	_fractionalBits = 8;

};

std::ostream&	operator<<(std::ostream &output, const Fixed& src);
