#include "Ice.h"
#include "ICharacter.h"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice& ref) : AMateria(ref.getType()) {}

std::string const& Ice::getType() const
{
    return AMateria::getType();
}

Ice* Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "Shoots an ice bolt at " << target.getName() << std::endl;
}
