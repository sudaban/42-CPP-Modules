#include "Weapon.h"

Weapon::Weapon(std::string type): type(type)
{
}

Weapon::~Weapon(void)
{
}

const std::string&	Weapon::getType(void)
{
	return (this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}