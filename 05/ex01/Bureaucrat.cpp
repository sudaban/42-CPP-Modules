#include "Bureaucrat.h"


Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade){
	std::cout << name << " initalized with " << grade << " grade." << std::endl;
}

Bureaucrat::~Bureaucrat(){ std::cout << "Destructor of " << this->name <<std::endl;}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        this->grade = other.getGrade();
    return *this;
}


Bureaucrat::Bureaucrat(const Bureaucrat& copy) {
	operator=(copy);
	std::cout << "copy constructor" << std::endl;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

void Bureaucrat::setGrade(int val)
{
	this->grade = val;
}

void Bureaucrat::increaseGrade()
{
	int grade = this->getGrade() - 1;
	if (grade  < 1)
		throw Bureaucrat::GradeTooHighException();
	else this->setGrade(grade);

	std::cout << this->getName() << "'s grade increased to: " << this->getGrade() <<std::endl;
}

void Bureaucrat::decraseGrade()
{
	int grade = this->getGrade() + 1;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else this->setGrade(grade);
	std::cout << this->getName() << "'s grade decreased to: " << this->getGrade() << std::endl;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bure)
{
    out << bure.getName() << ", bureaucrat grade " << bure.getGrade();
    return out;
}
