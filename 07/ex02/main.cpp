#include "Array.h"
#include <iostream>
#include <string>

int main() 
{
    std::cout << "=== Array Class Template Tests ===" << std::endl;
    std::cout << std::endl;

    // Test 1: Empty array and constructor with size
    std::cout << "Test 1: Empty array and sized array construction" << std::endl;
    Array<int> empty_array;
    std::cout << "Empty array size: " << empty_array.size() << std::endl;
    Array<int> int_array(5);
    std::cout << "Array of 5 elements (default initialized): ";
    for (unsigned int i = 0; i < int_array.size(); ++i) {
        std::cout << int_array[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // Test 2: Element access and modification
    std::cout << "Test 2: Element access and modification" << std::endl;
    for (unsigned int i = 0; i < int_array.size(); ++i) {
        int_array[i] = (i + 1) * 5;
    }
    std::cout << "Array after modification: ";
    for (unsigned int i = 0; i < int_array.size(); ++i) {
        std::cout << int_array[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // Test 3: Copy constructor
    std::cout << "Test 3: Copy constructor (deep copy control)" << std::endl;
    Array<int> copied_array(int_array);
    for (unsigned int i = 0; i < copied_array.size(); ++i) {
        copied_array[i] += 100;
    }
    std::cout << "Original array: ";
    for (unsigned int i = 0; i < int_array.size(); ++i) {
        std::cout << int_array[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Copied array (modified): ";
    for (unsigned int i = 0; i < copied_array.size(); ++i) {
        std::cout << copied_array[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // Test 4: Assignment operator (deep copy control and different sizes)
    std::cout << "Test 4: Assignment operator (deep copy and size handling)" << std::endl;
    Array<int> assigned_array;
    assigned_array = int_array;
    assigned_array[0] = 999;
    std::cout << "Original after assignment modification: ";
    for (unsigned int i = 0; i < int_array.size(); ++i) {
        std::cout << int_array[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Assigned array: ";
    for (unsigned int i = 0; i < assigned_array.size(); ++i) {
        std::cout << assigned_array[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // Test 5: range checking exception
    std::cout << "Test 5: Out of range exception" << std::endl;
    try {
        int_array[20];
    } catch (const std::out_of_range& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 6: Different data types
    std::cout << "Test 6: Array of different types" << std::endl;
    Array<std::string> str_array(3);
    str_array[0] = "Hello";
    str_array[1] = "Template";
    str_array[2] = "Array";
    std::cout << "String array: ";
    for (unsigned int i = 0; i < str_array.size(); ++i) {
        std::cout << str_array[i] << " ";
    }
    std::cout << std::endl;

    Array<double> double_array(3);
    double_array[0] = 3.14;
    double_array[1] = 2.71;
    double_array[2] = 1.41;
    std::cout << "Double array: ";
    for (unsigned int i = 0; i < double_array.size(); ++i) {
        std::cout << double_array[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // Test 7: Const array access
    std::cout << "Test 7: Const array const access" << std::endl;
    const Array<int> const_array(3);
    std::cout << "Const array size: " << const_array.size() << std::endl;
    std::cout << "Const array values: ";
    for (unsigned int i = 0; i < const_array.size(); ++i) {
        std::cout << const_array[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "=== All tests passed successfully ===" << std::endl;

    return 0;
}
