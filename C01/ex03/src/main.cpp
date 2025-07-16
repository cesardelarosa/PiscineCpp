#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main() {
  Weapon clubA = Weapon("crude spiked club");
  Weapon clubB = Weapon("crude spiked club");

  HumanA bob("Bob", clubA);
  bob.attack();
  clubA.setType("some other type of club");
  bob.attack();

  HumanB jim("Jim");
  jim.setWeapon(clubB);
  jim.attack();
  clubB.setType("some other type of club");
  jim.attack();
  return 0;
}