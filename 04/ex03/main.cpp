#include "AMateria.h"
#include "Character.h"
#include "Cure.h"
#include "Ice.h"
#include "ICharacter.h"
#include "IMateriaSource.h"
#include "MateriaSource.h"

int main()
{
    std::cout << "\nCONSTRUCTORS:\n-----------------------\n";
    IMateriaSource* materiaSource = new MateriaSource();
    materiaSource->learnMateria(new Ice());
    materiaSource->learnMateria(new Cure());
    ICharacter* playerCharacter = new Character("me");

    std::cout << "\nCREATE MATERIA:\n-----------------------\n";
    AMateria* iceMateria = materiaSource->createMateria("ice");
    playerCharacter->equip(iceMateria);
    AMateria* cureMateria = materiaSource->createMateria("cure");
    playerCharacter->equip(cureMateria);
    AMateria* nonExistentMateria = materiaSource->createMateria("fire");
    playerCharacter->equip(nonExistentMateria);

    std::cout << "\nUSE ON A NEW CHARACTER:\n-----------------------\n";
    ICharacter* npcCharacter = new Character("bob");
    playerCharacter->use(0, *npcCharacter);
    playerCharacter->use(1, *npcCharacter);
    playerCharacter->use(2, *npcCharacter); // Empty slot test
    playerCharacter->use(-4, *npcCharacter); // Invalid index test
    playerCharacter->use(18, *npcCharacter); // Invalid index test

    std::cout << "\nDEEP COPY CHARACTER:\n-----------------------\n";
    Character* copiedCharacter = new Character("Charles");
    AMateria* cureMateriaForCharles = materiaSource->createMateria("cure");
    copiedCharacter->equip(cureMateriaForCharles);
    AMateria* iceMateriaForCharles = materiaSource->createMateria("ice");
    copiedCharacter->equip(iceMateriaForCharles);
    AMateria* nonExistentMateriaForCharles = materiaSource->createMateria("earth");
    copiedCharacter->equip(nonExistentMateriaForCharles);
    Character* copiedCharacterClone = new Character(*copiedCharacter);

    std::cout << "\nDEEP COPY VS SOURCE:\n-----------------------\n";
    AMateria* leakedMateria = copiedCharacter->getMateriaFromInventory(0);
    copiedCharacter->unequip(0);
    delete leakedMateria;

    AMateria* clonedMateria = copiedCharacterClone->getMateriaFromInventory(1);
    copiedCharacterClone->unequip(1); // Prevent memory leak
    delete clonedMateria;
    AMateria* newCureMateria = materiaSource->createMateria("cure");
    copiedCharacterClone->equip(newCureMateria);
    AMateria* newIceMateria = materiaSource->createMateria("ice");
    copiedCharacterClone->equip(newIceMateria);

    std::cout << "\nUSE MATERIA FROM CHARACTERS:\n-----------------------\n";
    copiedCharacter->use(0, *npcCharacter);
    copiedCharacter->use(1, *npcCharacter);
    copiedCharacter->use(2, *npcCharacter);
    copiedCharacter->use(3, *npcCharacter);
    copiedCharacterClone->use(0, *npcCharacter);
    copiedCharacterClone->use(1, *npcCharacter);
    copiedCharacterClone->use(2, *npcCharacter);
    copiedCharacterClone->use(3, *npcCharacter);

    std::cout << "\nUNEQUIP TESTS:\n-----------------------\n";
    playerCharacter->unequip(-1); // Unequip invalid index
    playerCharacter->unequip(18); // Unequip invalid index
    playerCharacter->unequip(3);  // Unequip valid slot
    playerCharacter->use(1, *copiedCharacter);
    playerCharacter->unequip(1); // Unequip a valid slot (Cure)
    playerCharacter->use(1, *copiedCharacter); // Check for unequipped materia

    std::cout << "\nDESTRUCTORS:\n-----------------------\n";
    delete npcCharacter;
    delete playerCharacter;
    delete materiaSource;
    delete copiedCharacter;
    delete copiedCharacterClone;
    delete cureMateria;
    return 0;
}
