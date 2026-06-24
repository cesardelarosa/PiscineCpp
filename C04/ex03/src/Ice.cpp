#include "Ice.hpp"

#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& copy) : AMateria(copy) {}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice& rhs) {
  if (this != &rhs) {
    AMateria::operator=(rhs);
  }
  return *this;
}

AMateria* Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
