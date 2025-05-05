#include "Point.h"
#include <iostream>

int main() {
    Point a(0, Fixed(0));
    Point b(5, Fixed(0));
    Point c(0, Fixed(5));

    Point p_inside(1, Fixed(1));    // in → true
    Point p_outside(5, Fixed(5));   // Out → false
    Point p_edge(0, Fixed(2));      // Edge → false
    Point p_vertex(0, Fixed(0));    // Corner ->true

    std::cout << "Inside: " << bsp(a, b, c, p_inside) << std::endl;
    std::cout << "Outside: " << bsp(a, b, c, p_outside) << std::endl;
    std::cout << "On edge: " << bsp(a, b, c, p_edge) << std::endl;
    std::cout << "Vertex: " << bsp(a, b, c, p_vertex) << std::endl;

    return 0;
}
