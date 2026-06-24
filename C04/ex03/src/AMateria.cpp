#include "AMateria.hpp"

#include <iostream>

AMateria::AMateria() : type("default") {}

AMateria::AMateria(std::string const& type) : type(type) {}

AMateria::AMateria(const AMateria& copy) : type(copy.type) {}

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria& rhs) {
  if (this != &rhs) {
    // "While assigning a Materia to another, copying the type doesn't make
    // sense."
  }
  return *this;
}

std::string const& AMateria::getType() const { return this->type; }

void AMateria::use(ICharacter& target) {
  (void)target;
  // Base abstract use
}
