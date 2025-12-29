#include <iostream>
#include <vector>
#include <list>
#include "easyfind.h"

int main()
{
    std::cout << "--- Test 1: Vector ---" << std::endl;
    std::vector<int> vec;
	vec.push_back(10); 	vec.push_back(20); 	vec.push_back(30);

    try {
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "Found: " << *it << std::endl;
    }
	catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: List ---" << std::endl;
    std::list<int> lst;
	lst.push_back(100);	lst.push_back(200);	lst.push_back(300);


    try {
        std::list<int>::iterator it = easyfind(lst, 300);
        std::cout << "Found: " << *it << std::endl;
    }
	catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Error Case ---" << std::endl;
    try {
        easyfind(vec, 42);
    }
	catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}