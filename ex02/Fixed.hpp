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
	Fixed(Fixed& src);
	Fixed& operator=(Fixed& src);
	~Fixed();

	// Getters and Setters
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	// Functional members
	float			toFloat(void) const;
	int				toInt(void) const;
	static Fixed&	min(Fixed& num1, Fixed& num2);
	static Fixed&	max(Fixed& num1, Fixed& num2);
//	static Fixed&	min(Fixed& const num1, Fixed& const num2);
//	static Fixed&	max(Fixed& const num1, Fixed& const num2);
	bool			operator>(Fixed& src);
	bool			operator<(Fixed& src);
	bool			operator>=(Fixed& src);
	bool			operator<=(Fixed& src);
	bool			operator==(Fixed& src);
	bool			operator!=(Fixed& src);
	int				operator+(Fixed& src);
	int				operator-(Fixed& src);
	int				operator*(Fixed& src);
	float			operator/(Fixed& src);
	void			operator++(void);
	void			operator--(void);

private:
	int					_rawBits;
	static int const	_fractionalBits = 8;

};

std::ostream&	operator<<(std::ostream &output, const Fixed& src);
