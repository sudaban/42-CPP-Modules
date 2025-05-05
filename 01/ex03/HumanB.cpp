#include "HumanB.h"

HumanB::HumanB(std::string name): weapon(NULL)
{
	this->name = name;
	std::cout << "HumanB " << name << " created" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB " << this->name << " destroyed" << std::endl;
}

void HumanB::attack()
{
	
	std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}