#include "Weapon.hpp"

const std::string &Weapon::getType() { return _type; }

void Weapon::setType(std::string type) { _type = type; }

Weapon::Weapon(std::string type) { setType(type); }
Weapon::~Weapon() {}