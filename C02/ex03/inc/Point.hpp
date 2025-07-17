#pragma once
#include "Fixed.hpp"

class Point {
public:
    Point();
    Point(const Fixed x, const Fixed y);
    Point(const Point &copy);
    Point &operator=(const Point &rhs);
    ~Point();

    Fixed getX() const;
    Fixed getY() const;

    Point operator+(const Point &rhs) const;
    Point operator-(const Point &rhs) const;
    
    static Fixed det(const Point &u, const Point &v);
    static Fixed area(const Point &a, const Point &b, const Point &c);
    
private:
    const Fixed x;
    const Fixed y;
};
