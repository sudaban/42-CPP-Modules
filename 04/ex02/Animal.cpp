#include "Animal.h"

Animal::Animal() : m_type("NONE")
{
	std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal Copy Constructor called" << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Animal Assignation operator called" << std::endl;
	if (this != &src)
		this->m_type = src.m_type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "This animal doesn't make any sound." << std::endl;
}

std::string Animal::get_type() const
{
	return this->m_type;
}
