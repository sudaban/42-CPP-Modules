#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal
{
protected:
		std::string m_type;

public:
	Animal();
	Animal(const Animal &copy);
	virtual ~Animal();

	Animal &operator=(const Animal &src);

	virtual void makeSound() const = 0;
	std::string get_type() const;
};


#endif