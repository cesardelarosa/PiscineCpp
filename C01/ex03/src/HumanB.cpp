#include "HumanB.hpp"
#include <iostream>

void    HumanB::setWeapon(Weapon &weapon)
{
    _weapon = weapon;
}

void    HumanB::attack(void)
{
    if (_weapon.getType().empty())
        std::cout << _name << "tries to attack but fails at not having any weapon" << std::endl;
    else
        std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

HumanB::HumanB(std::string name) : _name(name), _weapon((Weapon)NULL){}
HumanB::~HumanB() {}
