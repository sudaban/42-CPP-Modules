#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "FragTrap.h"
#include "ScavTrap.h"

class DiamondTrap: public ScavTrap, public FragTrap
{
private:
	std::string name;
public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap(std::string name);
	virtual ~DiamondTrap();

	DiamondTrap &operator=(const DiamondTrap &src);

	void attack(const std::string &target);
	void whoAmI();
};

#endif