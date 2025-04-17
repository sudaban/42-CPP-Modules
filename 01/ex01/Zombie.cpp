#include "Zombie.h"

Zombie::Zombie(void)
{
	std::cout << "Constructor" << std::endl;
}

Zombie::~Zombie(void)
{
	if (this->name == "") this->name = "(EMPTY!)";
	std::cout << "Zombie with name: " << this->name << " destroyed." << std::endl;
}

void Zombie::set_name(std::string z_name)
{
	this->name = z_name;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}