#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << this->_name << " configuration complete!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
    *this = copy;
    std::cout << "ScavTrap " << this->_name << " has been copied!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->_name << " is destroyed!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_hitPoints = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }
    std::cout << "ScavTrap " << this->_name << " assignment operator called!" << std::endl;
    return *this;
}

void    ScavTrap::attack(const std::string& target)
{
    std::cout << "ScavTrap " << this->_name;
    if (this->_energyPoints == 0)
    {
        std::cout << " is out of energy and can't attack!" << std::endl;
        return;
    }
    if (this->_hitPoints == 0)
    {
        std::cout << " is broken and can't attack!" << std::endl;
        return;
    }
    this->_energyPoints--;
    std::cout << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void    ScavTrap::takeDamage(unsigned int amount)
{
    std::cout << "ScavTrap " << this->_name;
    if (this->_hitPoints == 0)
    {
        std::cout << " is already broken!" << std::endl;
        return;
    }
    if (this->_hitPoints < amount)
        this->_hitPoints = 0;
    else
        this->_hitPoints -= amount;
    std::cout << " takes " << amount << " points of damage! " << this->_hitPoints << " HP left." << std::endl;
}

void    ScavTrap::beRepaired(unsigned int amount)
{
    std::cout << "ScavTrap " << this->_name;
    if (this->_energyPoints == 0)
    {
        std::cout << " is out of energy and can't repair!" << std::endl;
        return;
    }
    if (this->_hitPoints == 0)
    {
        std::cout << " is broken and can't repair itself!" << std::endl;
        return;
    }
    this->_energyPoints--;
    this->_hitPoints += amount;
    std::cout << " repairs itself for " << amount << " hit points! Now has " << this->_hitPoints << " HP." << std::endl;
}

void    ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode.";
}