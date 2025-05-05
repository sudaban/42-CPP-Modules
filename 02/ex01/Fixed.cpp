#include "Fixed.h"
#include <iostream>
#include <cmath>

const int Fixed::bits = 8;

Fixed::Fixed()
{
	setRawBits(0);
	std::cout << "Default constructor called, setted val to 0" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


Fixed::Fixed(const int raw)
{
	std::cout << "Integer constructor called." << std::endl;
	this->val = raw << this->bits;
}

Fixed::Fixed(const float raw)
{
	std::cout << "Float constructor called." << std::endl;
	this->val = roundf(raw * (1 << this->bits));
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy Constructor called." << std::endl;
	operator=(copy);
}

Fixed& Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy asssigment" << std::endl;
	this->val = copy.getRawBits();
	return *this;
}

int Fixed::toInt() const
{
	return (this->val >> this->bits);
}

float Fixed::toFloat() const
{
	return ((float)this->val / (float)(1 << this->bits));
}

int Fixed::getRawBits() const
{
	return this->val;
}

void Fixed::setRawBits(const int new_val)
{
	this->val = new_val;
}