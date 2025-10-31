#include "AForm.h"

AForm::AForm(std::string name, int execGrade, int signGrade)
	: name(name), isSigned(false), execGrade(execGrade), signGrade(signGrade)
{
	std::cout << this->name << " initialized with grade values: "
	          << execGrade << " " << signGrade << std::endl;
}

AForm::~AForm() { std::cout << this->name << "'s destructor\n"; }

AForm::AForm(const AForm &other): name(other.getName() + "(copy)"), execGrade(other.getExecGrade()), signGrade(other.getSignGrade())
{
	std::cout << "AForm Copy Constructor called to copy " << other.getName() <<
	" into " << this->getName() << std::endl;
	*this = other;
}

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
		this->isSigned = src.isSigned;
	return *this;
}

void AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() >= this->signGrade){
		std::cout << b.getName() << " could'nt sign " << this->name << ", because form grade high.\n";
		throw AForm::GradeTooHighException();
	}
	this->isSigned = true;
	std::cout << b.getName() << " signed " << this->name << std::endl;
}

std::string AForm::getName() const{
	return this->name;
}

int AForm::getExecGrade() const{
	return this->execGrade;
}

int AForm::getSignGrade() const{
	return this->signGrade;
}

bool AForm::isSignedFunc() const {
	return this->isSigned;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() >= this->getExecGrade())
		throw AForm::GradeTooLowException();
	this->executeAction();
}

const char *AForm::GradeTooLowException::what() const throw(){
	return ("FORM'S GRADE TOO LOOOOOOOOOOOOOOOW");
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "FORM'S GRADE TOOOOOOOOOOO HIIIIIIIIIIIIIIIIIIIIIIIIIGH";
}

const char* AForm::FormNotSignedException::what() const throw(){
	return "FORM IS NOT SIGNED";
}