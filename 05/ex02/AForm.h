#ifndef AFORM_H
#define AFORM_H

#include <iostream>
#include "Bureaucrat.h"
class AForm
{
private:
	const std::string name;
	bool isSigned;
	const int execGrade;
	const int signGrade;
public:
	AForm(std::string name, int execGrade, int signGrade);
	AForm(const AForm& copy);
	virtual ~AForm();

	AForm& operator=(const AForm& other);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	void beSigned(Bureaucrat& b);
	int getExecGrade() const;
	int getSignGrade() const;
	std::string getName() const;
	bool isSignedFunc() const;

	// execute checks prerequisites and then calls action
	void execute(Bureaucrat const & executor) const;

protected:
	// concrete forms implement this to perform their specific action
	virtual void executeAction() const = 0;
};


#endif