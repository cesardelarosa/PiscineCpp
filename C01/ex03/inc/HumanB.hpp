#pragma once
#include "Weapon.hpp"

class HumanB {
public:
  HumanB(std::string name);
  ~HumanB();

  void attack();
  void setWeapon(Weapon &weapon);

private:
  std::string _name;
  Weapon *_weapon;
};