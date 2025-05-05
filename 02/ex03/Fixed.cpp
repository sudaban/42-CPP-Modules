#include "Fixed.h"

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

bool Fixed::operator>(Fixed op) const
{
	return this->toFloat() > op.toFloat();
}

bool Fixed::operator<(Fixed op) const
{
	return this->toFloat() < op.toFloat();
}

bool Fixed::operator>=(Fixed op) const
{
	return this->toFloat() >= op.toFloat();
}

bool Fixed::operator<=(Fixed op) const
{
	return this->toFloat() <= op.toFloat();
}

bool Fixed::operator==(Fixed op) const
{
	return this->toFloat() == op.toFloat();
}

bool Fixed::operator!=(Fixed op) const
{
	return this->toFloat() != op.toFloat();
}

Fixed Fixed::operator+(Fixed fixed) const
{
    return Fixed(this->toFloat() + fixed.toFloat());
}

float Fixed::operator-(Fixed op) const
{
	return this->toFloat() - op.toFloat();
}

float Fixed::operator*(Fixed op) const
{
	return this->toFloat() * op.toFloat();
}

float Fixed::operator/(Fixed op) const
{
	return this->toFloat() / op.toFloat();
}

// Overloaded pre-increment Operators
Fixed	Fixed::operator++()
{
	this->val++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->val--;
	return (*this);
}

// Overloaded post-increment Operators
Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	// i = this->_fp_value;
	++this->val;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	// i = this->_fp_value;
	--this->val;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
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

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return (os);
}