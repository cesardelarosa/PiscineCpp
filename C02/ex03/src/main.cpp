#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

void test_point(Point const &a, Point const &b, Point const &c, Point const &p_test, const std::string& label) {
    std::cout << "--- " << label << " ---" << std::endl;
    std::cout << "Point (" << p_test.getX() << ", " << p_test.getY() << ") ";
    
    if (bsp(a, b, c, p_test)) {
        std::cout << " is INSIDE the triangle." << std::endl;
    } else {
        std::cout << " is OUTSIDE the triangle" << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);

    std::cout << std::boolalpha;
    std::cout << "Triangle A(0,0), B(10,0), C(5,10)" << std::endl;
    std::cout << "================================================" << std::endl << std::endl;

    Point p_inside(5, 5);
    test_point(a, b, c, p_inside, "Inside Point");

    Point p_outside(15, 15);
    test_point(a, b, c, p_outside, "Outside Point");

    Point p_vertex(0, 0);
    test_point(a, b, c, p_vertex, "Vertex Point A");

    Point p_edge(7.5f, 0);
    test_point(a, b, c, p_edge, "Edge Point B-C");
    
    Point p_outside_close(-1, -1);
    test_point(a, b, c, p_outside_close, "Outside Close Point");

    return 0;
}