#ifndef INTERN_H
#define INTERN_H

#include <string>
#include <exception>

class AForm;

class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	~Intern();

	Intern& operator=(const Intern& other);

	AForm* makeForm(const std::string &formName, const std::string &target) const;

	class UnknownFormException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

#endif // INTERN_H