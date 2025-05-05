#include "Fixed.h"
#include <iostream>

int Fixed::other_val = 3;

Fixed::Fixed()
{
	setRawBits(0);
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copied)
{
	std::cout << "Copy constructor called" << std::endl;
	operator=(copied);
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->val = other.getRawBits();
	return *this;
}

int Fixed::getVal()
{
	return other_val;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->val;
}

void Fixed::setRawBits(int const raw)
{
	this->val = raw;
}