#include "ClapTrap.hpp"
#include <iostream>

int main() {
	ClapTrap clap("CL4P-TR4P");
	clap.attack("you");
	clap.takeDamage(5);
	clap.beRepaired(3);
	clap.takeDamage(8);
	clap.attack("me");
	clap.beRepaired(10);

	ClapTrap trap("CLAP-TRAP");
	trap.attack("target 1");
	trap.attack("target 2");
	trap.attack("target 3");
	trap.attack("target 4");
	trap.attack("target 5");
	trap.beRepaired(2);
	trap.beRepaired(2);
	trap.beRepaired(2);
	trap.beRepaired(2);
	trap.beRepaired(2);
	trap.beRepaired(2);

	return 0;
}