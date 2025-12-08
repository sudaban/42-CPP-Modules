#ifndef WHATEVER_H
#define WHATEVER_H

#include <iostream>

template<typename T>
void swap(T&a, T&b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
T const &min(T const &first, T const &second)
{
    return (first < second) ? first : second;
}

template<typename T>
T const &max(T const &first, T const &second)
{
    return (first > second) ? first : second;
}

#endif