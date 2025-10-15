#include "Bureaucrat.h"
#include "Form.h"

int main()
{
	// Bureaucrat b("Umut", 6);
	// Form form("test form", 5, 10);
	// try
	// {
	// 	form.beSigned(b);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	
	Bureaucrat a("Salih", 150);
	Form form2("2.form", 1, 55);
	try
	{
		form2.beSigned(a);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}