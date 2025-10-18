#include "DiamondTrap.hpp"
#include <iostream>

int main() {
	// --- Test 1: Construction and Special Ability ---
	std::cout << "--- DIAMONDBOT'S TEST ---" << std::endl;
	// Test virtual inheritance constructor chain
	// ClapTrap -> FragTrap -> ScavTrap -> DiamondTrap
	DiamondTrap diamondBot("DiamondBot");
	std::cout << std::endl;

	// --- Test 2: Member Function Resolution ---
	
	// 'attack' uses ScavTrap's version (20 damage)
	diamondBot.attack("an Enemy");

	// 'takeDamage' and 'beRepaired' are ambiguous
	// We must use scope resolution to specify which parent's version to use
	diamondBot.ScavTrap::takeDamage(40);
	diamondBot.ScavTrap::beRepaired(20);
	
	// Test 0 HP: Take fatal damage
	diamondBot.ScavTrap::takeDamage(80); // Now 0 HP
	std::cout << std::endl;

	// --- Test 3: Behavior at 0 HP ---
	diamondBot.attack("a Zombie"); // Should fail
	diamondBot.ScavTrap::beRepaired(50); // Should fail

	// Test new special ability 'whoAmI'
	diamondBot.whoAmI();
	std::cout << std::endl << std::endl;

	// --- Test 4: Orthodox Canonical Form (OCF) ---
	std::cout << "--- OCF COPY TEST ---" << std::endl;

	// Test copy constructor
	DiamondTrap diamondBotCopy(diamondBot);

	// Test assignment operator
	DiamondTrap diamondBotAssign("TempDiamondBot");
	diamondBotAssign = diamondBot;
	std::cout << std::endl;

	// --- Test 5: Destruction ---
	std::cout << "--- DESTRUCTION ---" << std::endl;
	// Test complex destructor chain in reverse order
	return 0;
}