#include "Point.h"

Point::Point() : x(Fixed(0)), y(Fixed(0))
{
	std::cout << "x and y setted 0 by default constructor" << std::endl;
}

Point::Point(const float n1, const Fixed n2) : x(Fixed(n1)), y(n2)
{
	std::cout << "floating n1 and fixed n2 setted by second constructor" << std::endl;
}

Point::Point(const Point& copy) : x(copy.x), y(copy.y)
{
	std::cout << "Copy Constructor" << std::endl;
}

Point& Point::operator=(const Point& other)
{
    if (this != &other) {
        this->x = other.x;
        this->y = other.y;
    }
    return *this;
}

Point::~Point()
{
	std::cout << "Destructor" << std::endl;
}

const Fixed &Point::get_x() const {
    return this->x;
}

const Fixed &Point::get_y() const
{
    return this->y;
}
