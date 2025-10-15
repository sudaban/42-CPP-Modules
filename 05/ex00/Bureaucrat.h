#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& copy);
	~Bureaucrat();


	Bureaucrat& operator=(const Bureaucrat& other);
	
	//getter
	int getGrade() const;
	std::string getName() const;

	//setter
	void setGrade(int val);
	
	void increaseGrade();
	void decraseGrade();

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};



#endif 