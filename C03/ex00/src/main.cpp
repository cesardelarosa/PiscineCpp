#include "ClapTrap.hpp"
#include <iostream>

int main() {
	// --- Test 1: Basic functionality ---
	std::cout << "--- CLAPPY'S TEST ---" << std::endl;
	ClapTrap clappy("Clappy");

	// Test actions: attack (0 damage), take damage, repair
	clappy.attack("you");
	clappy.takeDamage(5);
	clappy.beRepaired(3);

	// Test 0 HP: Take fatal damage, then try actions
	clappy.takeDamage(8); // Now has 0 HP
	clappy.attack("me"); // Should fail
	clappy.beRepaired(10); // Should fail

	std::cout << std::endl;

	// --- Test 2: 0 Energy test ---
	std::cout << "--- TRAPPY'S TEST ---" << std::endl;
	ClapTrap trappy("Trappy");

	// Deplete all 10 energy points by attacking
	trappy.attack("Target 1");
	trappy.attack("Target 2");
	trappy.attack("Target 3");
	trappy.attack("Target 4");
	trappy.attack("Target 5");
	trappy.attack("Target 6");
	trappy.attack("Target 7");
	trappy.attack("Target 8");
	trappy.attack("Target 9");
	trappy.attack("Target 10"); // Now has 0 EP

	// Test actions with 0 energy
	trappy.attack("Target 11"); // Should fail
	trappy.beRepaired(2); // Should fail

	std::cout << std::endl;
	std::cout << "--- DESTRUCTION ---" << std::endl;
	// Destructors called for trappy, then clappy
	return 0;
}