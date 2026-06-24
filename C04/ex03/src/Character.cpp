#include "Character.hpp"

#include <iostream>

Character::Character() : name("default_character") {
  for (int i = 0; i < 4; i++) inventory[i] = NULL;
}

Character::Character(std::string const& name) : name(name) {
  for (int i = 0; i < 4; i++) inventory[i] = NULL;
}

Character::Character(const Character& copy) : name(copy.name) {
  for (int i = 0; i < 4; i++) {
    if (copy.inventory[i])
      inventory[i] = copy.inventory[i]->clone();
    else
      inventory[i] = NULL;
  }
}

Character::~Character() {
  for (int i = 0; i < 4; i++) {
    if (inventory[i]) delete inventory[i];
  }
}

Character& Character::operator=(const Character& rhs) {
  if (this != &rhs) {
    name = rhs.name;
    for (int i = 0; i < 4; i++) {
      if (inventory[i]) delete inventory[i];
      if (rhs.inventory[i])
        inventory[i] = rhs.inventory[i]->clone();
      else
        inventory[i] = NULL;
    }
  }
  return *this;
}

std::string const& Character::getName() const { return name; }

void Character::equip(AMateria* m) {
  if (!m) return;
  for (int i = 0; i < 4; i++) {
    if (inventory[i] == NULL) {
      inventory[i] = m;
      return;
    }
  }
}

void Character::unequip(int idx) {
  if (idx >= 0 && idx < 4) {
    inventory[idx] = NULL;  // Do not delete the Materia
  }
}

void Character::use(int idx, ICharacter& target) {
  if (idx >= 0 && idx < 4 && inventory[idx]) {
    inventory[idx]->use(target);
  }
}
