#include "Form.h"

Form::Form(std::string name, int execGrade, int signGrade)
	: name(name), isSigned(false), execGrade(execGrade), signGrade(signGrade)
{
	std::cout << this->name << " initialized with grade values: "
	          << execGrade << " " << signGrade << std::endl;
}

Form::~Form() { std::cout << this->name << "'s destructor\n"; }

Form::Form(const Form &other): name(other.getName() + "(copy)"), execGrade(other.getExecGrade()), signGrade(other.getSignGrade())
{
	std::cout << "Form Copy Constructor called to copy " << other.getName() <<
	" into " << this->getName() << std::endl;
	*this = other;
}

Form &Form::operator=(const Form &src)
{
	if (this != &src)
		this->isSigned = src.isSigned;
	return *this;
}

void Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() >= this->signGrade){
		std::cout << b.getName() << " could'nt sign " << this->name << ", because form grade high.\n";
		throw Form::GradeTooHighException();
	}
	this->isSigned = true;
	std::cout << b.getName() << " signed " << this->name << std::endl;
}

std::string Form::getName() const{
	return this->name;
}

int Form::getExecGrade() const{
	return this->execGrade;
}

int Form::getSignGrade() const{
	return this->signGrade;
}

const char *Form::GradeTooLowException::what() const throw(){
	return ("FORM'S GRADE TOO LOOOOOOOOOOOOOOOW");
}

const char* Form::GradeTooHighException::what() const throw(){
	return "FORM'S GRADE TOOOOOOOOOOO HIIIIIIIIIIIIIIIIIIIIIIIIIGH";
}