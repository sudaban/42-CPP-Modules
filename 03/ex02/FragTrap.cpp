#include "FragTrap.h"

FragTrap::FragTrap() : ClapTrap()
{
    this->hit_points = 100;
    this->energy = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
    this->hit_points = copy.hit_points;
    this->energy = copy.energy;
    this->attack_damage = copy.attack_damage;
    std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    this->hit_points = 100;
    this->energy = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap Constructor for \"" << this->name << "\" called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor for \"" << this->name << "\" called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& src)
{
    std::cout << "FragTrap Assignment Operator called" << std::endl;
    if (this != &src)
    {
        this->name = src.name;
        this->hit_points = src.hit_points;
        this->energy = src.energy;
        this->attack_damage = src.attack_damage;
    }
    return *this;
}

void FragTrap::highFiveGuys()
{
    std::cout << "FragTrap \"" << this->name << "\": gimme a FIVEEEEEe" << std::endl;
}
