#include "Cat.h"


Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat Constructor" << std::endl;
}

Cat::Cat(const Cat& copy)
{
	*this = copy;
	std::cout << "Cat class copy constructor" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat class destructor" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat: MEOW MEOW NIGGA" << std::endl;
}