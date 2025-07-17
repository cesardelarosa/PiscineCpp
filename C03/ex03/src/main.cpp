#include "DiamondTrap.hpp"
#include <iostream>

int main() {
	DiamondTrap diamond("DI4M-TP");
	std::cout << std::endl;

	diamond.attack("enemy");
	diamond.ScavTrap::takeDamage(40);
	diamond.ScavTrap::beRepaired(20);
	diamond.ScavTrap::takeDamage(80);
	std::cout << std::endl;

	diamond.attack("zombie");
	diamond.ScavTrap::beRepaired(50);
	diamond.whoAmI();
	std::cout << std::endl;

	DiamondTrap diamond_copy(diamond);
	DiamondTrap diamond_assign("TEMP-DIAMOND");
	diamond_assign = diamond;
	std::cout << std::endl;

	return 0;
}