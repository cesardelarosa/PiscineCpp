#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
    FragTrap frag("FR4G-TP");
    frag.highFivesGuys();
    std::cout << std::endl;

    frag.attack("enemy");
    frag.takeDamage(40);
    frag.beRepaired(20);
    frag.takeDamage(80);
    std::cout << std::endl;

    frag.attack("zombie");
    frag.beRepaired(50);
    frag.highFivesGuys();
    std::cout << std::endl;

    FragTrap frag_copy(frag);
    FragTrap frag_assign("TEMP-FRAG");
    frag_assign = frag;
    std::cout << std::endl;

    return 0;
}