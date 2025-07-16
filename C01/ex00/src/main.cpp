#include "Zombie.hpp"

int main() {
  Zombie *heap_zombie;

  heap_zombie = newZombie("Heapy");
  heap_zombie->announce();
  delete heap_zombie;

  randomChump("Stacky");
  return 0;
}