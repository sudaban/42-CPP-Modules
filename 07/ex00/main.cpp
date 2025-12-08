#include "whatever.h"


int main()
{
    int a = 2, b = 3;
    std::cout << "Before: a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "After: a = " << a << ", b = " << b << std::endl;

    int c = 4, d = 5;
    std::cout << "min(" << c << ", " << d << "): " << min(c, d) << std::endl;
    std::cout << "max(" << c << ", " << d << "): " << max(c, d) << std::endl;
}