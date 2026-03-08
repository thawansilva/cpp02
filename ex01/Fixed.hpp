#pragma once
#include <iostream>

class Fixed
{
public:
	Fixed(int const num);
	~Fixed(void);
	Fixed(const Fixed& src);
	Fixed& operator=(const Fixed& src);
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	std::ostream& operator<<(std::ostream &output, const Fixed& src);

private:
	int					_value;
	static int const	_fract_bits;
};
