#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.h"

class Character : public ICharacter
{
private:
    AMateria *materiaInventory[4];
    const std::string characterName;

public:
    Character(std::string name);
    Character(const Character &ref);
    ~Character();

    Character &operator=(const Character &ref);

    std::string const &getName() const;
    void equip(AMateria *materia);
    void unequip(int index);
    void use(int index, ICharacter &target);
    AMateria *getMateriaFromInventory(int index);
};

#endif
