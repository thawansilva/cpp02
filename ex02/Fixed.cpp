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

Fixed::Fixed(Fixed& src)
{
//	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed& Fixed::operator=(Fixed& src)
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

bool	Fixed::operator>(Fixed& src)
{
	return (this->toInt() > src.toInt());
}

bool	Fixed::operator<(Fixed& src)
{
	return (this->toInt() < src.toInt());
}

bool	Fixed::operator>=(Fixed& src)
{
	return (this->toInt() >= src.toInt());
}

bool	Fixed::operator<=(Fixed& src)
{
	return (this->toInt() <= src.toInt());
}

bool	Fixed::operator==(Fixed& src)
{
	return (this->toInt() == src.toInt());
}

bool	Fixed::operator!=(Fixed& src)
{
	return (this->toInt() != src.toInt());
}

int		Fixed::operator+(Fixed& src)
{
	return (this->toInt() + src.toInt());
}

int		Fixed::operator-(Fixed& src)
{
	return (this->toInt() - src.toInt());
}

int		Fixed::operator*(Fixed& src)
{
	return (this->toInt() * src.toInt());
}

float	Fixed::operator/(Fixed& src)
{
	return (float)(this->toFloat() / src.toFloat());
}

void	Fixed::operator++(void)
{
	return this->setRawBits(this->getRawBits() + 1);
}

void	Fixed::operator--(void)
{
	return this->setRawBits(this->getRawBits() - 1);
}

Fixed&	min(Fixed& num1, Fixed& num2)
{
	return (num1 < num2);
}

Fixed&	max(Fixed& num1, Fixed& num2)
{
	return (num1 > num2);
}

//Fixed&	min(Fixed& const num1, Fixed& const num2)
//{
//	return (num1 < num2);
//}
//
//Fixed&	max(Fixed& const num1, Fixed& const num2)
//{
//	return (num1 > num2);
//}

std::ostream& operator<<(std::ostream &output, Fixed const &src)
{
	output << src.toFloat();
	return (output);
}
