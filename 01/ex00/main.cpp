#include "Zombie.h"

int main()
{
	Zombie zombie("42>1337");
	zombie.announce();
	randomChump("noByte");

	Zombie *new_zombie = newZombie("newzombie");
	delete new_zombie;
	return 0;
}
