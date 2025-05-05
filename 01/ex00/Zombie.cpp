#include "Zombie.h"

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "Zombie created with name: " << this->name  << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie destroyed with name: " << this->name << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
