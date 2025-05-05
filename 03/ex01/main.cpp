#include "ScavTrap.h"

int main()
{
    std::cout << "--- Testing ScavTrap ---" << std::endl;
    ScavTrap scav1("Scavvy");
    ScavTrap scav2(scav1);
    scav2.attack("Boss");
    scav2.guardGate();
    scav2.guardGate();
    scav2.takeDamage(20);
    scav2.beRepaired(10);

    std::cout << std::endl;

    std::cout << "--- Testing Assignment Operator ---" << std::endl;
    ScavTrap scav3;
    scav3 = scav2;
    scav3.attack("MiniBoss");

    return 0;
}
