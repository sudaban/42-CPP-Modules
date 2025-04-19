#include "Harl.h"
#include <iostream>

int main()
{
	Harl harl;

	harl.complain("INFO");
	std::cout << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	harl.complain("ERROR");

	std::cout << std::endl;
	harl.complain("hello_world");
}