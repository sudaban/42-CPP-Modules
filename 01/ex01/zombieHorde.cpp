#include "Zombie.h"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cout << "A zombie horde with 0 members? What is this, a ghost town?" << std::endl;
		return NULL;
	}

	Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        horde[i].set_name(name);
    }
    return horde;
}