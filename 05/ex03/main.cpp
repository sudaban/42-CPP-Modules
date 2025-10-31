#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "Intern.h"
#include <iostream>

int main()
{
	Intern someRandomIntern;
	Bureaucrat high("High", 1);
	Bureaucrat low("Low", 150);

	AForm* form = NULL;

	try {
		form = someRandomIntern.makeForm("robotomy request", "Bender");
		if (form)
		{
			try { form->beSigned(high); } catch (const std::exception &e) { std::cerr << e.what() << std::endl; }
			high.executeForm(*form);
			delete form;
			form = NULL;
		}
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		form = someRandomIntern.makeForm("shrubbery creation", "home");
		if (form)
		{
			try { form->beSigned(high); } catch (const std::exception &e) { std::cerr << e.what() << std::endl; }
			high.executeForm(*form);
			low.executeForm(*form);
			delete form;
			form = NULL;
		}
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		form = someRandomIntern.makeForm("presidential pardon", "Arthur");
		if (form)
		{
			try { form->beSigned(high); } catch (const std::exception &e) { std::cerr << e.what() << std::endl; }
			high.executeForm(*form);
			delete form;
			form = NULL;
		}
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		form = someRandomIntern.makeForm("unknown form", "Nobody");
		delete form;
	}
	catch (const std::exception &e) {
		std::cerr << "Expected failure: " << e.what() << std::endl;
	}

	return 0;
}