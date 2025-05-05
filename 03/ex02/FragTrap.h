#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.h"

class FragTrap: public ClapTrap
{
private:
public:
	FragTrap();
	FragTrap(const FragTrap &copy);
	FragTrap(const std::string& name);
	~FragTrap();

	FragTrap &operator=(const FragTrap &src);

	void highFiveGuys();
};

#endif