#include "Character.h"

Character::Character(std::string name) : characterName(name)
{
    for (int i = 0; i < 4; ++i)
        materiaInventory[i] = NULL;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (this->materiaInventory[i]) {
            delete this->materiaInventory[i];
        }
    }
    std::cout << "Character named " << this->characterName << " was destroyed\n";
}


std::string const &Character::getName() const
{
    return characterName;
}

Character::Character(const Character &ref) : characterName(ref.getName() + "_copy")
{
    for (int i = 0; i < 4; ++i)
    {
        if (ref.materiaInventory[i])
            materiaInventory[i] = ref.materiaInventory[i]->clone();
        else
            materiaInventory[i] = NULL;
    }
}


Character &Character::operator=(const Character &ref)
{
    if (this != &ref)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (materiaInventory[i])
                delete materiaInventory[i];
            if (ref.materiaInventory[i])
                materiaInventory[i] = ref.materiaInventory[i]->clone();
            else
                materiaInventory[i] = NULL;
        }
    }
    return *this;
}


void Character::equip(AMateria *materia)
{
    if (!materia)
    {
        std::cout << characterName << " tried to equip nothing." << std::endl;
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        if (!materiaInventory[i])
        {
            materiaInventory[i] = materia;
            std::cout << characterName << " equipped materia " << materia->getType() << " in slot " << i << "." << std::endl;
            return;
        }
    }

    std::cout << characterName << " can't equip more than 4 Materia." << std::endl;
}

void Character::unequip(int index)
{
    if (index < 0 || index >= 4 || !materiaInventory[index])
    {
        std::cout << characterName << " has nothing equipped at slot " << index << "." << std::endl;
        return;
    }

    std::cout << characterName << " unequipped " << materiaInventory[index]->getType() << " from slot " << index << "." << std::endl;
    materiaInventory[index] = NULL;
}

void Character::use(int index, ICharacter &target)
{
    if (index < 0 || index >= 4 || !materiaInventory[index])
    {
        std::cout << "Nothing found to use at index " << index << std::endl;
        return;
    }

    materiaInventory[index]->use(target);
}

AMateria *Character::getMateriaFromInventory(int index)
{
    return materiaInventory[index];
}
