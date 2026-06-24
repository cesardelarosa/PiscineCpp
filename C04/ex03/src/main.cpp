#include <iostream>

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void printHeader(std::string const& title) {
  std::cout << "\n=== " << title << " ===" << std::endl;
}

int main() {
  /* 1. SUBJECT MAIN TEST */
  printHeader("SUBJECT MAIN TEST");

  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter* me = new Character("me");

  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);

  ICharacter* bob = new Character("bob");

  me->use(0, *bob);
  me->use(1, *bob);

  delete bob;
  delete me;
  delete src;

  /* 2. MATERIA SOURCE OVERFLOW TEST */
  printHeader("MATERIA SOURCE OVERFLOW TEST");

  IMateriaSource* src2 = new MateriaSource();
  src2->learnMateria(new Ice());
  src2->learnMateria(new Cure());
  src2->learnMateria(new Ice());
  src2->learnMateria(new Cure());
  src2->learnMateria(new Ice());

  delete src2;
  std::cout << "MateriaSource overflow handled cleanly." << std::endl;

  /* 3. INVENTORY OVERFLOW TEST */
  printHeader("INVENTORY OVERFLOW TEST");

  IMateriaSource* src3 = new MateriaSource();
  src3->learnMateria(new Ice());
  ICharacter* me2 = new Character("me2");

  me2->equip(src3->createMateria("ice"));
  me2->equip(src3->createMateria("ice"));
  me2->equip(src3->createMateria("ice"));
  me2->equip(src3->createMateria("ice"));

  AMateria* extraMateria = src3->createMateria("ice");
  me2->equip(extraMateria);

  delete extraMateria;

  delete me2;
  delete src3;
  std::cout << "Inventory overflow handled cleanly." << std::endl;

  /* 4. DOUBLE EQUIP TEST */
  printHeader("DOUBLE EQUIP TEST");

  IMateriaSource* src4 = new MateriaSource();
  src4->learnMateria(new Cure());
  ICharacter* me3 = new Character("me3");

  AMateria* doubleMateria = src4->createMateria("cure");
  me3->equip(doubleMateria);
  me3->equip(doubleMateria);

  me3->use(0, *me3);
  me3->use(1, *me3);

  delete me3;
  delete src4;
  std::cout << "Double equip prevented cleanly." << std::endl;

  /* 5. UNEQUIP TEST (TRASH HANDLING) */
  printHeader("UNEQUIP TEST");

  IMateriaSource* src5 = new MateriaSource();
  src5->learnMateria(new Ice());
  ICharacter* me4 = new Character("me4");

  AMateria* unequipMateria = src5->createMateria("ice");
  me4->equip(unequipMateria);
  me4->unequip(0);

  me4->use(0, *me4);

  delete me4;
  delete src5;
  std::cout << "Unequip and trash cleanup handled cleanly." << std::endl;

  /* 6. DEEP COPY TEST */
  printHeader("DEEP COPY TEST");

  IMateriaSource* src6 = new MateriaSource();
  src6->learnMateria(new Cure());

  Character* original = new Character("Original");
  original->equip(src6->createMateria("cure"));

  Character* copy = new Character(*original);

  original->unequip(0);

  std::cout << "Original using slot 0 (should be empty):" << std::endl;
  original->use(0, *copy);

  std::cout << "Copy using slot 0 (should work):" << std::endl;
  copy->use(0, *original);

  delete original;
  delete copy;
  delete src6;

  printHeader("ALL TESTS COMPLETED");
  return 0;
}
