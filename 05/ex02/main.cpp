#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

int main()
{
	Bureaucrat high("High", 1);
	Bureaucrat low("Low", 150);

	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pres("Arthur");

	try { shrub.beSigned(high); } catch(const std::exception &e) { std::cerr << e.what() << std::endl; }
	try { robot.beSigned(high); } catch(const std::exception &e) { std::cerr << e.what() << std::endl; }
	try { pres.beSigned(high); } catch(const std::exception &e) { std::cerr << e.what() << std::endl; }

	high.executeForm(shrub);
	low.executeForm(shrub);

	high.executeForm(robot);
	high.executeForm(pres);

	return 0;
}