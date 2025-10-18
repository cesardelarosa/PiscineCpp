#include "ScavTrap.hpp"
#include <iostream>

int main() {
	// --- Test 1: Construction and Special Ability ---
	std::cout << "--- SCAVVY'S TEST ---" << std::endl;
	// Test constructor chain: ClapTrap -> ScavTrap
	ScavTrap scavvy("Scavvy");

	// Test new special ability
	scavvy.guardGate();
	std::cout << std::endl;

	// --- Test 2: Combat Functionality ---
	// Test overridden attack (20 damage)
	scavvy.attack("a Bad Guy");
	scavvy.takeDamage(30);
	scavvy.beRepaired(10);

	// Test 0 HP: Take fatal damage
	scavvy.takeDamage(80); // Now 0 HP
	std::cout << std::endl;

	// Test actions at 0 HP
	scavvy.attack("the void"); // Should fail
	scavvy.beRepaired(20); // Should fail
	scavvy.guardGate(); // Should still work
	std::cout << std::endl << std::endl;

	// --- Test 3: Orthodox Canonical Form (OCF) ---
	std::cout << "--- OCF COPY TEST ---" << std::endl;
	
	// Test copy constructor
	ScavTrap scavvyCopy(scavvy);

	// Test assignment operator
	ScavTrap scavvyAssign("TempBot");
	scavvyAssign = scavvy;
	std::cout << std::endl;

	// --- Test 4: Destruction ---
	std::cout << "--- DESTRUCTION ---" << std::endl;
	// Destructors called in reverse order
	return 0;
}