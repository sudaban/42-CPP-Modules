#include "Dog.h"
#include <stdlib.h>

#include "Dog.h"

Dog::Dog() : Animal()
{
	std::cout << "Dog Default Constructor called" << std::endl;
	this->m_type = "Dog";
	this->m_brain = new Brain();
	if (!this->m_brain)
	{
		std::cerr << "Dog's brain creation failed. Exiting..." << std::endl;
		exit(1);
	}
}

Dog::Dog(const Dog &copy) : Animal()
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	this->m_brain = new Brain();
	if (!this->m_brain)
	{
		std::cerr << "Dog's brain creation failed. Exiting..." << std::endl;
		exit(1);
	}
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete this->m_brain;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog Assignation operator called" << std::endl;
	if (this != &src)
	{
		this->m_type = src.m_type;
		if (this->m_brain)
			delete this->m_brain;
		this->m_brain = new Brain();
		if (!this->m_brain)
		{
			std::cerr << "Dog's brain creation failed. Exiting..." << std::endl;
			exit(1);
		}
		*this->m_brain = *src.m_brain;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << this->get_type() << ": Woof woof!" << std::endl;
}

void Dog::get_idea() const
{
	for (int i = 0; i < 100; i++)
		std::cout << "Idea " << i << ": \"" << this->m_brain->get_idea(i) << "\" at address " << this->m_brain->get_idea_adr(i) << std::endl;
}

void Dog::set_idea(int i, std::string idea)
{
	this->m_brain->set_idea(i, idea);
}
