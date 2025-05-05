#include "Point.h"

Fixed area(Point const a, Point const b, Point const c)
{
    Fixed result = (a.get_x() * (b.get_y() - c.get_y()) +
                    b.get_x() * (c.get_y() - a.get_y()) +
                    c.get_x() * (a.get_y() - b.get_y())) / 2;
    if (result < 0)
        result = result * -1;
    return result;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed total_area = area(a, b, c);
    Fixed area1 = area(point, b, c);
    Fixed area2 = area(a, point, c);
    Fixed area3 = area(a, b, point);

    if (area1 == 0 || area2 == 0 || area3 == 0)
        return false;
    if (total_area == (area1 + area2 + area3))
        return true;
    return false;
}
