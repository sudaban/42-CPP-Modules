#ifndef FORM_H
#define FORM_H

#include <iostream>
#include "Bureaucrat.h"
class Form
{
private:
	const std::string name;
	bool isSigned;
	const int execGrade;
	const int signGrade;
public:
	Form(std::string name, int execGrade, int signGrade);
	Form(const Form& copy);
	~Form();

	Form& operator=(const Form& other);

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

	void beSigned(Bureaucrat& b);
	int getExecGrade() const;
	int getSignGrade() const;
	std::string getName() const;
};


#endif