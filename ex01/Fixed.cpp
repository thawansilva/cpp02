#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0), _fract_bits(8)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const num) : _value(num), _fract_bits(8)
{
	std::cout << "Int constructor called" << std::endl;
	// converts num to the correspondig fixed-point value
}

Fixed::Fixed(float const num) : _value(num), _fract_bits(8)
{
	std::cout << "Float constructor called" << std::endl;
	// converts num to the correspondig fixed-point value
}

Fixed::~Fixed(void)
{
	std::cout << "Default called" << std::endl;
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
	    _value = src._value;
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void	Fixed::setRawBits(int value)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = value;
}

std::ostream& operator<<(std::ostream &output, const Fixed& src);
{
	output << src.getRawBits();
	return (output)
}
