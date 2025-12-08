#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <typename T>
class Array
{
private:
    T* m_data;
    unsigned int m_size;

public:
    Array(void) : m_data(NULL), m_size(0) {}

    Array(unsigned int n) : m_data(NULL), m_size(n) 
    {
        if (n > 0) {
            m_data = new T[n]();
        }
    }

    Array(const Array& copy) : m_data(NULL), m_size(copy.m_size)
    {
        if (m_size > 0) {
            m_data = new T[m_size];
            for (unsigned int i = 0; i < m_size; ++i) {
                m_data[i] = copy.m_data[i];
            }
        }
    }

    ~Array() 
    {
        if (m_data != NULL) { // if m_data is not null means allocated.
            delete[] m_data;
        }
    }

    Array& operator=(const Array& other) 
    {
        if (this != &other) {
            // Delete existing data
            if (m_data != NULL) {
                delete[] m_data;
                m_data = NULL;
            }

            // Copy data from other
            m_size = other.m_size;
            if (m_size > 0) {
                m_data = new T[m_size];
                for (unsigned int i = 0; i < m_size; ++i) {
                    m_data[i] = other.m_data[i];
                }
            }
        }
        return *this;
    }

    // Subscript operator, non-const access
    T& operator[](unsigned int index)
    {
        if (index >= m_size) {
            throw std::out_of_range("Array index out of range");
        }
        return m_data[index];
    }

    // Subscript operator, const access
    const T& operator[](unsigned int index) const
    {
        if (index >= m_size) {
            throw std::out_of_range("Array index out of range");
        }
        return m_data[index];
    }

    unsigned int size(void) const { return m_size; }
};

#endif