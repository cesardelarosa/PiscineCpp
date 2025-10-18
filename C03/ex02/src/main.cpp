#include "FragTrap.hpp"
#include <iostream>

int main() {
	// --- Test 1: Construction and Special Ability ---
	std::cout << "--- FRAGGY'S TEST ---" << std::endl;
	// Test constructor chain: ClapTrap -> FragTrap
	FragTrap fraggy("Fraggy");

	// Test new special ability
	fraggy.highFivesGuys();
	std::cout << std::endl << std::endl;

	// --- Test 2: Combat Functionality ---
	// Test overridden attack (30 damage)
	fraggy.attack("an Enemy");
	fraggy.takeDamage(40);
	fraggy.beRepaired(20);
	
	// Test 0 HP: Take fatal damage
	fraggy.takeDamage(80); // Now 0 HP
	std::cout << std::endl;

	// Test actions at 0 HP
	fraggy.attack("a Zombie"); // Should fail
	fraggy.beRepaired(50); // Should fail
	fraggy.highFivesGuys(); // Should still work
	std::cout << std::endl << std::endl;

	// --- Test 3: Orthodox Canonical Form (OCF) ---
	std::cout << "--- OCF COPY TEST ---" << std::endl;

	// Test copy constructor
	FragTrap fraggyCopy(fraggy);

	// Test assignment operator
	FragTrap fraggyAssign("TempFragBot");
	fraggyAssign = fraggy;
	std::cout << std::endl;

	// --- Test 4: Destruction ---
	std::cout << "--- DESTRUCTION ---" << std::endl;
	// Destructors called in reverse order
	return 0;
}