#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

class Point
{
private:
    Fixed x;
    Fixed y;

public:
    Point();
    Point(const float n1, const Fixed n2);
    Point(const Point& copy);
    Point& operator=(const Point& other);
    ~Point();

    const Fixed &get_x() const;
    const Fixed &get_y() const;
};

Fixed area(Point const a, Point const b, Point const c);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif