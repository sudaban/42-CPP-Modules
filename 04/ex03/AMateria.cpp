#include "AMateria.h"

AMateria::AMateria() : m_type("")
{
    std::cout << "AMateria object created" << std::endl;
}

AMateria::AMateria(std::string const &type) : m_type(type)
{
    std::cout << "AMateria object created with type: " << m_type << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "AMateria object destroyed" << std::endl;
}

AMateria::AMateria(AMateria const &ref) : m_type(ref.m_type)
{
    std::cout << "AMateria object created from a copy with type: " << m_type << std::endl;
}

std::string const &AMateria::getType() const
{
    return this->m_type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "AMateria used on " << target.getName() << std::endl;
}
