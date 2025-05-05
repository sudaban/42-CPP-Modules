#include "Dog.h"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog class constructor" << std::endl;
}


Dog::Dog(const Dog& copy)
{
	std::cout << "Dog Copy Constructor" << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "Dog class destructor" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog: WOOF WOOF!" << std::endl;
}