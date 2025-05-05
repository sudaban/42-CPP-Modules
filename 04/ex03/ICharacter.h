#ifndef ICHARACTER_H
#define ICHARACTER_H

#include "AMateria.h"

class AMateria;

class ICharacter
{
protected:
    const std::string characterName;

public:
    virtual ~ICharacter() {}

    virtual const std::string& getName() const = 0;
    virtual void equip(AMateria* materia) = 0;
    virtual void unequip(int index) = 0;
    virtual void use(int index, ICharacter& target) = 0;
};

#endif
