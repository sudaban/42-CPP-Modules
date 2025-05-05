#include "Brain.h"

#include "Brain.h"

Brain::Brain()
{
	std::cout << "Brain Constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = "";
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; ++i)
			this->ideas[i] = src.ideas[i];
	}
	return *this;
}

const std::string Brain::get_idea(int i) const
{
	if (i >= 0 && i < 100)
		return this->ideas[i];
	return "Invalid index (0-99)";
}

const std::string* Brain::get_idea_adr(int i) const
{
	if (i >= 0 && i < 100)
		return &this->ideas[i];
	return NULL;
}

void Brain::set_idea(int i, std::string idea)
{
	if (i >= 0 && i < 100)
		this->ideas[i] = idea;
	else
		std::cout << "Invalid index. Brain supports only 100 ideas (0-99)." << std::endl;
}
