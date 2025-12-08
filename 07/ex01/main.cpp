#include "iter.h"
#include <iostream>
#include <string>

void printInt(const int& x) { std::cout << x << " "; }

void incrementInt(int& x) { x++; }

void printString(const std::string& str) { std::cout << "[" << str << "] "; }

void appendString(std::string& str) { str += "!"; }


template <typename T>
void print(const T& x) {
    std::cout << x << " ";
}

int main() 
{
    std::cout << "Test 1: Print integers" << std::endl;
    int intArray[5] = {1, 2, 3, 4, 5};
    iter(intArray, 5, printInt);
    std::cout << std::endl;

    std::cout << "Test 2: Increment integers" << std::endl;
    iter(intArray, 5, incrementInt);
    std::cout << "After increment: ";
    iter(intArray, 5, printInt);
    std::cout << std::endl;

    std::cout << "Test 3: Print strings" << std::endl;
    std::string stringArray[3] = {"Hello", "World", "C++"};
    iter(stringArray, 3, printString);
    std::cout << std::endl;

    std::cout << "Test 4: Append to strings" << std::endl;
    iter(stringArray, 3, appendString);
    std::cout << "After append: ";
    iter(stringArray, 3, printString);
    std::cout << std::endl;

    std::cout << "Test 5: Using function template" << std::endl;
    iter(intArray, 5, print<int>);
    std::cout << std::endl;

    std::cout << "Test 6: Using function template with strings" << std::endl;
    iter(stringArray, 3, print<std::string>);
    std::cout << std::endl;

    return 0;
}
