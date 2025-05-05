#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat: public Animal
{
private:
public:
	Cat();
	Cat(const Cat& copy);
	~Cat();

	void makeSound() const;
};

#endif