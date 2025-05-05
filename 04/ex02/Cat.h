#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include "Brain.h"

class Cat: public Animal
{
private:
	Brain *m_brain;

public:
	Cat();
	Cat(const Cat &copy);
	~Cat();

	Cat &operator=(const Cat &src);

	void makeSound() const;
	void get_idea() const;
	void set_idea(int i, std::string idea);
};

#endif