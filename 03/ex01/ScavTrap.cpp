#include "ScavTrap.h"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->hit_points = 100;
    this->energy = 50;
    this->attack_damage = 20;
    this->gate_guard = false;
    std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    this->hit_points = 100;
    this->energy = 50;
    this->attack_damage = 20;
    this->gate_guard = false;
    std::cout << "ScavTrap Constructor for \"" << this->name << "\" called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
    this->gate_guard = copy.gate_guard;
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor for \"" << this->name << "\" called" << std::endl;
}


ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
    if (this != &src)
    {
        ClapTrap::operator=(src);
        this->gate_guard = src.gate_guard;
    }
    std::cout << "ScavTrap Assignment Operator called" << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->hit_points > 0 && this->energy > 0)
    {
        std::cout << "ScavTrap \"" << this->name << "\" attacks " << target
                  << ", causing " << this->attack_damage << " points of damage!" << std::endl;
        --this->energy;
    }
    else if (this->energy == 0)
    {
        std::cout << "ScavTrap \"" << this->name << "\" cannot attack, no energy left." << std::endl;
    }
    else
    {
        std::cout << "ScavTrap \"" << this->name << "\" cannot attack, not enough hit points." << std::endl;
    }
}

void ScavTrap::guardGate()
{
    if (!this->gate_guard)
    {
        this->gate_guard = true;
        std::cout << "ScavTrap \"" << this->name << "\" has entered Gate Keeper mode." << std::endl;
    }
    else
    {
        std::cout << "ScavTrap \"" << this->name << "\" is already guarding the gate." << std::endl;
    }
}
