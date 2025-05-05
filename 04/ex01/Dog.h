#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include "Brain.h"

class Dog: public Animal
{
private:
	Brain *m_brain;

public:
	Dog();
	Dog(const Dog &copy);
	~Dog();

	Dog &operator=(const Dog &src);

	void makeSound() const;
	void get_idea() const;
	void set_idea(int i, std::string idea);
};

#endif