#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    ScavTrap scav("SC4V-TP");
    scav.guardGate();
    std::cout << std::endl;

    scav.attack("bad guy");
    scav.takeDamage(30);
    scav.beRepaired(10);
    scav.takeDamage(80);
    std::cout << std::endl;

    scav.attack("the void");
    scav.beRepaired(20);
    scav.guardGate();
    std::cout << std::endl;

    ScavTrap scav_copy(scav);
    ScavTrap scav_assign("TEMP");
    scav_assign = scav;
    std::cout << std::endl;

    return 0;
}