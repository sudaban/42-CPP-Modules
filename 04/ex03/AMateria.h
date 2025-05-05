#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include "ICharacter.h"

class ICharacter;

class AMateria
{
protected:
    const std::string m_type;
public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(AMateria const & ref);
    virtual ~AMateria();
 
    AMateria &operator=(AMateria const &other);

    virtual std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
    
};

#endif
