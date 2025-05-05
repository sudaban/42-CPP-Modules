#ifndef CURE_H
# define CURE_H

#include "AMateria.h"

class Cure : public AMateria
{
public:
    Cure();
    Cure(const Cure &ref);
    ~Cure();

    Cure &operator=(const Cure &ref);

    std::string const &getType() const;
    Cure *clone() const;
    void use(ICharacter &target);
};

#endif
