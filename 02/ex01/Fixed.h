#ifndef FIXED_H
#define FIXED_H

#include <ostream>

class Fixed
{
private:
	int val;
	static const int bits;
public:
	Fixed();
	~Fixed();
	Fixed(const int val);
	Fixed(const float val);
	Fixed(const Fixed& copy);
	
	Fixed &operator=(const Fixed &copy);

	float toFloat() const;
	int	toInt() const;

	int getRawBits() const;
	void setRawBits(const int raw);
};


#endif