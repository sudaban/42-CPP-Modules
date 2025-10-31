#include "RobotomyRequestForm.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
: AForm(target, 45, 72), target(target)
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other), target(other.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		this->target = other.target;
	return *this;
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "BZZZZZZ... DRILLING NOISES..." << std::endl;
	int r = std::rand() % 2;
	if (r == 0)
		std::cout << this->getName() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed on " << this->getName() << std::endl;
}
