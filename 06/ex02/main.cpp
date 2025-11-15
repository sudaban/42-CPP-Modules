#include <iostream>
#include "identify.h"

int main() 
{
	for (int i = 0; i < 3; ++i)
	{
		Base* obj = generate();
		std::cout << "Pointer identify: ";
		identify(obj);
		std::cout << "Reference identify: ";
		identify(*obj);
		delete obj;
		std::cout << "---" << std::endl;
	}
	return 0;
}
