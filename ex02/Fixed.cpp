/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:32:44 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/10 21:23:14 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _rawBits(0)
{}

Fixed::Fixed(int const num_i): _rawBits(num_i << _fractionalBits)
{}

Fixed::Fixed(float const num_f): _rawBits(roundf(num_f * (1 << _fractionalBits)))
{}

Fixed::~Fixed(void)
{}

Fixed::Fixed(const Fixed& src)
{
	*this = src;
}

Fixed& Fixed::operator=(const Fixed& src)
{
	if (this != &src)
		_rawBits = src.getRawBits();
	return *this;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (float)(1 << _fractionalBits));
}

int	Fixed::toInt(void) const
{
	return this->_rawBits >> _fractionalBits;
}

int	Fixed::getRawBits(void) const
{
	return _rawBits;
}

void	Fixed::setRawBits(int value)
{
	_rawBits = value;
}

bool	Fixed::operator>(const Fixed src) const
{
	return (this->_rawBits > src._rawBits);
}

bool	Fixed::operator<(const Fixed src) const
{
	return (this->_rawBits < src._rawBits);
}

bool	Fixed::operator>=(const Fixed src) const
{
	return (this->_rawBits >= src._rawBits);
}

bool	Fixed::operator<=(const Fixed src) const
{
	return (this->_rawBits <= src._rawBits);
}

bool	Fixed::operator==(const Fixed src) const
{
	return (this->_rawBits == src._rawBits);
}

bool	Fixed::operator!=(const Fixed src) const
{
	return (this->_rawBits != src._rawBits);
}

Fixed	Fixed::operator+(const Fixed src) const
{
	return Fixed(this->_rawBits + src._rawBits);
}

Fixed	Fixed::operator-(const Fixed src) const
{
	return Fixed(this->_rawBits - src._rawBits);
}

Fixed	Fixed::operator*(const Fixed src) const
{
	return Fixed(this->toFloat() * src.toFloat());
}

Fixed	Fixed::operator/(const Fixed src) const
{
	return Fixed(this->toFloat() / src.toFloat());
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	this->_rawBits++;
	return (temp);
}

Fixed&	Fixed::operator++(void)
{
	this->_rawBits++;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	this->_rawBits--;
	return (temp);
}

Fixed&	Fixed::operator--(void)
{
	this->_rawBits--;
	return (*this);
}

Fixed&	Fixed::min(Fixed& num1, Fixed& num2)
{
	return (num1 < num2 ? num1 : num2);
}

Fixed&	Fixed::max(Fixed& num1, Fixed& num2)
{
	return (num1 > num2 ? num1 : num2);
}

const Fixed&	Fixed::min(const Fixed& num1, const Fixed& num2)
{
	return (num1 < num2 ? num1 : num2);
}

const Fixed&	Fixed::max(const Fixed& num1, const Fixed& num2)
{
	return (num1 > num2 ? num1 : num2);
}

std::ostream& operator<<(std::ostream &output, const Fixed &src)
{
	output << src.toFloat();
	return (output);
}
