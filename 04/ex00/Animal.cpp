#include "Animal.h"

Animal::Animal()
{
	type = "NONE";
	std::cout << "Animal class default constructor" << std::endl;
}

Animal::Animal(const std::string& copy)
{
	std::cout << "Animal Class copy constructor" << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Animal class default destructor" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Thats not means every animal have a sound!!!" << std::endl;
}

std::string Animal::get_type() const
{
	return this->type;
}