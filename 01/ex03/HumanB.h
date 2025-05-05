#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"
#include "iostream"

class HumanB
{
	private:
		std::string	name;
		Weapon	*weapon;
	public:
		HumanB(std::string name);
		~HumanB(void);
		
		void attack(void);
		void setWeapon(Weapon &weapon);
};

#endif