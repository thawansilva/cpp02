#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const num_i): _rawBits(num_i << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const num_f): _rawBits(roundf(num_f * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed& Fixed::operator=(const Fixed& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
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

std::ostream& operator<<(std::ostream &output, Fixed const &src)
{
	output << src.toFloat();
	return (output);
}
