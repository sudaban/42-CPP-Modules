#include "DiamondTrap.h"

int main()
{
    DiamondTrap dt("Shiny");

    std::cout << "\n-- Testing attack() --" << std::endl;
    dt.attack("EnemyBot");

    std::cout << "\n-- Testing whoAmI() --" << std::endl;
    dt.whoAmI();

    std::cout << "\n-- Testing highFiveGuys() (from FragTrap) --" << std::endl;
    dt.highFiveGuys();

    std::cout << "\n-- Testing guardGate() (from ScavTrap) --" << std::endl;
    dt.guardGate();

    std::cout << "\n-- Testing takeDamage() and beRepaired() --" << std::endl;
    dt.takeDamage(20);
    dt.beRepaired(15);

    std::cout << "\n-- Done --" << std::endl;

    return 0;
}
