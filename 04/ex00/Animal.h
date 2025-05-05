#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const std::string& copy);
	virtual ~Animal();
	
	std::string get_type() const;
	virtual void makeSound() const;
};


#endif