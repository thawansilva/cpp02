/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:32:44 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/09 21:25:59 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _rawBits(0)
{
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const num_i): _rawBits(num_i << _fractionalBits)
{
//	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const num_f): _rawBits(roundf(num_f * (1 << _fractionalBits)))
{
//	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
//	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
//	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed& Fixed::operator=(const Fixed& src)
{
//	std::cout << "Copy assignment operator called" << std::endl;
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

bool	Fixed::operator>(const Fixed& src) const
{
	return (this->toInt() > src.toInt());
}

bool	Fixed::operator<(const Fixed& src) const
{
	return (this->toInt() < src.toInt());
}

bool	Fixed::operator>=(const Fixed& src) const
{
	return (this->toInt() >= src.toInt());
}

bool	Fixed::operator<=(const Fixed& src) const
{
	return (this->toFloat() <= src.toFloat());
}

bool	Fixed::operator==(const Fixed& src) const
{
	return (this->getRawBits() == src.getRawBits());
}

bool	Fixed::operator!=(const Fixed& src) const
{
	return (this->toInt() != src.toInt());
}

int		Fixed::operator+(const Fixed& src) const
{
	return (this->toInt() + src.toInt());
}

int		Fixed::operator-(const Fixed& src) const
{
	return (this->toInt() - src.toInt());
}

float	Fixed::operator*(const Fixed src) const
{
	return (float)(this->toFloat() * src.toFloat());
}

float	Fixed::operator/(const Fixed& src) const
{
	return (float)(this->toFloat() / src.toFloat());
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (temp);
}

Fixed&	Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (temp);
}

Fixed&	Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed&	Fixed::min(Fixed& num1, Fixed& num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

Fixed&	Fixed::max(Fixed& num1, Fixed& num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

const Fixed&	Fixed::min(const Fixed& num1, const Fixed& num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

const Fixed&	Fixed::max(const Fixed& num1, const Fixed& num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

std::ostream& operator<<(std::ostream &output, const Fixed &src)
{
	output << src.toFloat();
	return (output);
}
