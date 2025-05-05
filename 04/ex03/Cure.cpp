#include "Cure.h"
#include "ICharacter.h"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure &ref) : AMateria(ref.getType()) {}

std::string const &Cure::getType() const
{
    return AMateria::getType();
}

Cure *Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
    std::cout << "Heals " << target.getName() << "'s wounds" << std::endl;
}
