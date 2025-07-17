#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed areaABC = Point::area(a, b, c);
    Fixed areaPAB = Point::area(point, a, b);
    Fixed areaPBC = Point::area(point, b, c);
    Fixed areaPCA = Point::area(point, c, a);

    return (areaABC == (areaPAB + areaPBC + areaPCA));
}