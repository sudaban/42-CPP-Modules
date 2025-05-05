#include "DiamondTrap.h"

DiamondTrap::DiamondTrap()
	: ClapTrap("DEFAULT_CLAP"), ScavTrap(), FragTrap()
{
	this->name = "DEFAULT_DIA";
	this->hit_points = FragTrap::hit_points;
	this->energy = ScavTrap::energy;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
	: ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_CLAP"), ScavTrap(), FragTrap()
{
	this->name = name;
	this->hit_points = FragTrap::hit_points;
	this->energy = ScavTrap::energy;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap Constructor for the name " << this->name << " called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor for " << this->name << " called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	if (this != &src)
	{
		ClapTrap::operator=(src);
		this->name = src.name;
	}
	return *this;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "Hello, I am DiamondTrap named " << this->name
			  << ", derived from ClapTrap named " << ClapTrap::name << "." << std::endl;
}
