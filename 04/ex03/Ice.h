#ifndef ICE_H
#define ICE_H

#include "AMateria.h"

class Ice : public AMateria
{
public:
    Ice();
    Ice(const Ice& ref);
    ~Ice();

    Ice& operator=(const Ice& ref);

    std::string const& getType() const;
    Ice* clone() const;
    void use(ICharacter& target);    
};

#endif
