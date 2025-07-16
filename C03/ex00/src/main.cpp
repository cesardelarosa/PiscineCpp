#include <iostream>
#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("CL4P-TP");
    clap.attack("un Skag");
    clap.takeDamage(5);
    clap.beRepaired(3);
    clap.takeDamage(8);
    clap.attack("el aire");
    clap.beRepaired(10);

    ClapTrap trap("TR4P-TP");
    trap.attack("objetivo 1");
    trap.attack("objetivo 2");
    trap.attack("objetivo 3");
    trap.attack("objetivo 4");
    trap.attack("objetivo 5");
    trap.beRepaired(2);
    trap.beRepaired(2);
    trap.beRepaired(2);
    trap.beRepaired(2);
    trap.beRepaired(2);
    trap.beRepaired(2);

    return 0;
}