#include "Cat.h"
#include <stdlib.h>

#include "Cat.h"

Cat::Cat() : Animal()
{
	std::cout << "Cat Default Constructor called" << std::endl;
	this->m_type = "Cat";
	this->m_brain = new Brain();
	if (!this->m_brain)
	{
		std::cerr << "Failed to allocate Brain. Exiting." << std::endl;
		exit(1);
	}
}

Cat::Cat(const Cat &copy) : Animal()
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->m_brain = new Brain();
	if (!this->m_brain)
	{
		std::cerr << "Failed to allocate Brain. Exiting." << std::endl;
		exit(1);
	}
	*this = copy;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete this->m_brain;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat Assignation operator called" << std::endl;
	if (this != &src)
	{
		this->m_type = src.m_type;
		if (this->m_brain)
			delete this->m_brain;
		this->m_brain = new Brain();
		if (!this->m_brain)
		{
			std::cerr << "Failed to allocate Brain. Exiting." << std::endl;
			exit(1);
		}
		*this->m_brain = *src.m_brain;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << this->get_type() << ": Meow meow nigga!" << std::endl;
}

void Cat::get_idea() const
{
	for (int i = 0; i < 100; i++)
		std::cout << "Idea " << i << ": \"" << this->m_brain->get_idea(i) << "\" at address " << this->m_brain->get_idea_adr(i) << std::endl;
}

void Cat::set_idea(int i, std::string idea)
{
	this->m_brain->set_idea(i, idea);
}
