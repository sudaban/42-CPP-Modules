#include "ClapTrap.h"
#include <iostream>

#define MAX_HIT_POINTS 10
#define DEFAULT_HIT_POINTS 10
#define DEFAULT_ENERGY 10
#define DEFAULT_ATTACK_DAMAGE 0

ClapTrap::ClapTrap() :
    name("Default"),
    hit_points(DEFAULT_HIT_POINTS),
    energy(DEFAULT_ENERGY),
    attack_damage(DEFAULT_ATTACK_DAMAGE)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) :
    name(name),
    hit_points(DEFAULT_HIT_POINTS),
    energy(DEFAULT_ENERGY),
    attack_damage(DEFAULT_ATTACK_DAMAGE)
{
    std::cout << "Constructor for ClapTrap \"" << this->name << "\" called" << std::endl;
}


ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called for ClapTrap \"" << this->name << "\"" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy = other.energy;
        this->attack_damage = other.attack_damage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->hit_points == 0)
    {
        std::cout << "\033[31mClapTrap " << this->name << " can't attack because it has no hit points.\033[0m" << std::endl;
        return;
    }
    if (this->energy == 0)
    {
        std::cout << "\033[31mClapTrap " << this->name << " can't attack because it has no energy.\033[0m" << std::endl;
        return;
    }

    std::cout << "ClapTrap " << this->name << " attacks " << target
              << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    this->energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_points == 0)
    {
        std::cout << "\033[33mClapTrap " << this->name << " is already dead, stop beating it.\033[0m" << std::endl;
        return;
    }

    if (amount >= (unsigned int)this->hit_points)
        this->hit_points = 0;
    else
        this->hit_points -= amount;

    std::cout << "ClapTrap " << this->name << " takes " << amount << " damage, "
              << "remaining hit points: " << this->hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hit_points == 0)
    {
        std::cout << "\033[31mClapTrap " << this->name << " can't repair itself because it is dead.\033[0m" << std::endl;
        return;
    }
    if (this->energy == 0)
    {
        std::cout << "\033[31mClapTrap " << this->name << " has no energy to repair itself.\033[0m" << std::endl;
        return;
    }
    if (this->hit_points + amount > MAX_HIT_POINTS)
    {
        std::cout << "\033[33mClapTrap " << this->name << " can't exceed max hit points (" << MAX_HIT_POINTS << ").\033[0m" << std::endl;
        return;
    }

    this->hit_points += amount;
    this->energy--;
    std::cout << "ClapTrap " << this->name << " repairs itself by " << amount
              << ", now has " << this->hit_points << " hit points." << std::endl;
}
