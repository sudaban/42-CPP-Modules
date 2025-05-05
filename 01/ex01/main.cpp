#include "Zombie.h"


int main() {
	int horde_count = 3;
    Zombie* horde = zombieHorde(horde_count, "Zombie42");

    if (horde == NULL)
    {
        std::cout << "Failed to create zombie horde." << std::endl;
        return 1;
    }

    for (int i = 0; i < horde_count; i++)
    {
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}