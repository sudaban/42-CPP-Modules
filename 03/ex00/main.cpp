#include "ClapTrap.h"

int main()
{
    std::cout << "===== Creating ClapTraps =====" << std::endl;
    
    ClapTrap a("Aamon");
    ClapTrap b("Balmond");
    ClapTrap c(a); // Copy constructor test

    std::cout << "\n===== Basic Actions =====" << std::endl;
    
    a.attack("Balmond");
    b.takeDamage(3);
    b.beRepaired(2);
    std::cout << "\n===== Energy Depletion Test =====" << std::endl;

    for (int i = 0; i < 11; ++i)
        a.attack("Dyrroth");

    std::cout << "\n===== Death and Overheal Tests =====" << std::endl;

    b.takeDamage(10);
    b.attack("Phoveus");
    b.beRepaired(1);

    std::cout << "\n===== Repair Beyond Max HP =====" << std::endl;

    c.beRepaired(5);  // Should work
    c.beRepaired(10); // Should give warning

    std::cout << "\n===== Copy Assignment Test =====" << std::endl;

    ClapTrap d;
    d = a;

    std::cout << "\n===== Program End =====" << std::endl;

    return 0;
}
