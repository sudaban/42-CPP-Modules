#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap: virtual public ClapTrap
{
private:
	bool gate_guard;
public:
	ScavTrap();
	ScavTrap(const ScavTrap &copy);
	ScavTrap(const std::string& name);
	~ScavTrap();

	ScavTrap &operator=(const ScavTrap &src);

	void attack(const std::string &target);
	void guardGate();
};

#endif