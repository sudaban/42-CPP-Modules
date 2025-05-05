#include "MateriaSource.h"
#include "AMateria.h"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        inventory[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i])
        {
            inventory[i] = other.inventory[i]->clone();
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete inventory[i];
            if (other.inventory[i])
            {
                inventory[i] = other.inventory[i]->clone();
            }
            else
            {
                inventory[i] = NULL;
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        delete inventory[i];
    }
}

void MateriaSource::learnMateria(AMateria* materia)
{
    int i = 0;
    while (i < 4 && inventory[i] != NULL)
    {
        i++;
    }

    if (i < 4)
    {
        inventory[i] = materia;
    }
    else
    {
        std::cout << "Cannot learn more than 4 Materia.\n";
    }
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
    int i = 0;
    while (i < 4 && (inventory[i] == NULL || inventory[i]->getType() != type))
    {
        i++;
    }

    if (i < 4 && inventory[i])
    {
        return inventory[i]->clone();
    }
    else
    {
        std::cout << type << " materia does not exist.\n";
        return NULL;
    }
}
