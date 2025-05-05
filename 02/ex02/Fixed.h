#ifndef FIXED_H
#define FIXED_H

#include <ostream>
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int val;
	static const int bits;
public:
	Fixed();
	Fixed(const float val);
	Fixed(const int val);
	Fixed(const Fixed &copy);
	~Fixed();

	Fixed &operator=(const Fixed &other);
	bool operator>(Fixed fixed)const;
	bool operator<(Fixed fixed)const;
	bool operator>=(Fixed fixed)const;
	bool operator<=(Fixed fixed)const;
	bool operator==(Fixed fixed)const;
	bool operator!=(Fixed fixed)const;
	float operator+(Fixed fixed)const;
	float operator-(Fixed fixed)const;
	float operator*(Fixed fixed)const;
	float operator/(Fixed fixed)const;

	// pre-increment
	Fixed operator++();
	Fixed operator--();

	// post-increment 
	Fixed operator++(int);
	Fixed operator--(int);

	int getRawBits() const;
	void setRawBits(const int raw);

	float toFloat() const;
	int	toInt() const;

	static Fixed &max(Fixed &first, Fixed &second);
	static const Fixed &max(Fixed const &first, Fixed const &second);
	static Fixed &min(Fixed &first, Fixed &second);
	static const Fixed &min(Fixed const &first, Fixed const &second);
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif