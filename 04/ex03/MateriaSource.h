#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.h"

class MateriaSource : public IMateriaSource
{
private:
    AMateria* inventory[4];

public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    ~MateriaSource();

    MateriaSource& operator=(const MateriaSource& other);

    void learnMateria(AMateria* materia);
    AMateria* createMateria(const std::string& type);
};

#endif
