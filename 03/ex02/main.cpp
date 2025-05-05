#include "FragTrap.h"

int main()
{
    std::cout << "=== FragTrap Test ===" << std::endl;
    FragTrap frag1("Fraggy");
    FragTrap frag2(frag1); // Copy constructor
    frag2.attack("Target4");
    frag2.takeDamage(40);
    frag2.beRepaired(30);
    frag2.highFiveGuys();
    std::cout << std::endl;

    std::cout << "=== Assignment Operator Test ===" << std::endl;
    FragTrap frag3;
    frag3 = frag1;
    frag3.highFiveGuys();
}
