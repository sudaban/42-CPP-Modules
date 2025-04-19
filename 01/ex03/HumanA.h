#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"
#include <iostream>

class	HumanA
{
	private:
		std::string	name;
		Weapon		&weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void attack();
		void setWeapon(Weapon weapon);
};

#endif