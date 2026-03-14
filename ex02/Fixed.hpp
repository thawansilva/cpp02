/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:32:53 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/14 15:09:52 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(const int num_i);
	Fixed(const float num_f);
	Fixed(const Fixed& src);
	Fixed& operator=(const Fixed& src);
	~Fixed();

	// Getters and Setters
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	// Functional members
	int					toInt(void) const;
	float				toFloat(void) const;
	static Fixed&		min(Fixed& num1, Fixed& num2);
	static Fixed&		max(Fixed& num1, Fixed& num2);
	static const Fixed&	min(const Fixed& num1, const Fixed& num2);
	static const Fixed&	max(const Fixed& num1, const Fixed& num2);
	// Relational operators
	bool				operator>(const Fixed &src) const;
	bool				operator<(const Fixed &src) const;
	bool				operator>=(const Fixed &src) const;
	bool				operator<=(const Fixed &src) const;
	bool				operator==(const Fixed &src) const;
	bool				operator!=(const Fixed &src) const;
	// Arithmetic operators
	Fixed				operator+(const Fixed &src) const;
	Fixed				operator-(const Fixed &src) const;
	Fixed				operator*(const Fixed &src) const;
	Fixed				operator/(const Fixed &src) const;
	// Increment/decrement
	Fixed				operator++(int);
	Fixed				operator--(int);
	Fixed&				operator++(void);
	Fixed&				operator--(void);

private:
	int					_rawBits;
	static int const	_fractionalBits = 8;
};

std::ostream&	operator<<(std::ostream &output, const Fixed& src);
