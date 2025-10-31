#include "Intern.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) { (void)other; }

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

const char* Intern::UnknownFormException::what() const throw()
{
	return "Intern: requested form does not exist";
}

// Helper function type for creating AForm*
typedef AForm* (*MakeFn)(const std::string &);

static AForm* makeShrub(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* makeRobot(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

static AForm* makePresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
	// mapping of names to factory functions
	const std::string names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	MakeFn fns[] = { &makeShrub, &makeRobot, &makePresidential };
	const int count = 3;

	for (int i = 0; i < count; ++i)
	{
		if (formName == names[i])
		{
			AForm* form = fns[i](target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}

	std::cout << "Intern couldn't create form because name '" << formName << "' is unknown" << std::endl;
	throw Intern::UnknownFormException();
}
