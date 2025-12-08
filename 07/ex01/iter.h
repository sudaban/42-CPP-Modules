#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename T>
void iter(T* array, const size_t length, void (*func)(T)) // value
{
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

template <typename T>
void iter(T* array, const size_t length, void (*func)(const T&)) // const ref
{
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

template <typename T>
void iter(T* array, const size_t length, void (*func)(T&)) // ref
{
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

#endif

