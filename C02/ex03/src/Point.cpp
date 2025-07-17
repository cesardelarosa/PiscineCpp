#include "Point.hpp"
#include <cmath>

Point::Point() : x(0), y(0) {}

Point::Point(const Fixed x, const Fixed y) : x(x), y(y) {}

Point::Point(const Point &copy) : x(copy.x), y(copy.y) {}

Point &Point::operator=(const Point &rhs) {
    if (this != &rhs) {
        // Assignment to const members is not allowed, so we do nothing here.
    }
    return *this;
}

Point::~Point() {}

Fixed Point::getX() const {
    return this->x;
}

Fixed Point::getY() const {
    return this->y;
}

Point Point::operator+(const Point &rhs) const {
    return Point(this->x + rhs.x, this->y + rhs.y);
}

Point Point::operator-(const Point &rhs) const {
    return Point(this->x - rhs.x, this->y - rhs.y);
}

Fixed Point::det(const Point &u, const Point &v) {
    return (u.getX() * v.getY() - u.getY() * v.getX());
}

Fixed Point::area(const Point &a, const Point &b, const Point &c)
{
    Point vector_ab = b - a;
    Point vector_ac = c - a;

    Fixed det_value = Point::det(vector_ab, vector_ac);
    if (det_value < Fixed(0)){
        det_value = det_value * Fixed(-1);
    }
    return det_value / Fixed(2.0f);
}