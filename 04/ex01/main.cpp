#include "Dog.h"
#include "Cat.h"

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include <iostream>

int main()
{
	std::cout << "\033[34m=== Constructing Animals ===\033[0m" << std::endl;
	const Animal* animals[10];
	for (int i = 0; i < 10; ++i)
	{
		if (i % 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();

		if (!animals[i])
		{
			std::cerr << "Memory allocation failed. Exiting..." << std::endl;
			return -1;
		}
	}
	std::cout << std::endl;

	std::cout << "\033[34m=== Testing Animals ===\033[0m" << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "[Animal " << i << "] Type: " << animals[i]->get_type() << std::endl;
		animals[i]->makeSound();
	}
	std::cout << std::endl;

	std::cout << "\033[34m=== Deconstructing Animals ===\033[0m" << std::endl;
	for (int i = 0; i < 10; ++i)
		delete animals[i];

	std::cout << std::endl;
	std::cout << "\033[34m=== Deep Copy Test ===\033[0m" << std::endl;

	Dog* a = new Dog();
	if (!a)
	{
		std::cerr << "Memory allocation failed for Dog a. Exiting..." << std::endl;
		return -1;
	}

	a->set_idea(0, "I have to sniff it");
	a->set_idea(1, "I have to pee on it");
	a->set_idea(2, "I have to sniff it again");
	a->set_idea(101, "invalid index test");

	Dog* b = new Dog(*a);
	if (!b)
	{
		std::cerr << "Memory allocation failed for Dog b. Exiting..." << std::endl;
		delete a;
		return -1;
	}

	std::cout << std::endl;
	std::cout << "\033[34m=== Dog a Ideas ===\033[0m" << std::endl;
	a->get_idea();
	std::cout << std::endl;

	std::cout << "\033[34m=== Deleting Dog a ===\033[0m" << std::endl;
	delete a;
	std::cout << std::endl;

	std::cout << "\033[34m=== Dog b Ideas After Copy ===\033[0m" << std::endl;
	b->get_idea();
	std::cout << std::endl;

	std::cout << "\033[34m=== Deleting Dog b ===\033[0m" << std::endl;
	delete b;

	return 0;
}
