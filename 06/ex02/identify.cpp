#include "identify.h"
#include "Derived.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void) {
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	int r = std::rand() % 3;
	if (r == 0) return new A();
	if (r == 1) return new B();
	return new C();
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
	else std::cout << "Unknown" << std::endl;
}

void identify(Base& p) {
	try {
		A& ra = dynamic_cast<A&>(p);
		(void)ra;
		std::cout << "A" << std::endl;
		return;
	} catch (...) {}
	try {
		B& rb = dynamic_cast<B&>(p);
		(void)rb;
		std::cout << "B" << std::endl;
		return;
	} catch (...) {}
	try {
		C& rc = dynamic_cast<C&>(p);
		(void)rc;
		std::cout << "C" << std::endl;
		return;
	} catch (...) {}
	std::cout << "Unknown" << std::endl;
}
