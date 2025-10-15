#include "Bureaucrat.h"


int main()
{
	Bureaucrat b("Umut", 1);
	try
	{
		b.increaseGrade();	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Bureaucrat b2("Salih", 150);
	try
	{
		b2.decraseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Bureaucrat b3("sdaban", 44);
	b3.increaseGrade();
	b3.increaseGrade();
	b3.increaseGrade();
	b3.increaseGrade();
	b3.increaseGrade();

	return 0;
}