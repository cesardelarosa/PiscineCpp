#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap " << this->_name << " configuration complete!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
    *this = copy;
    std::cout << "FragTrap " << this->_name << " has been copied!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->_name << " is destroyed!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_hitPoints = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }
    std::cout << "FragTrap " << this->_name << " assignment operator called!" << std::endl;
    return *this;
}

void    FragTrap::attack(const std::string& target)
{
    std::cout << "FragTrap " << this->_name;
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

void    FragTrap::takeDamage(unsigned int amount)
{
    std::cout << "FragTrap " << this->_name;
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

void    FragTrap::beRepaired(unsigned int amount)
{
    std::cout << "FragTrap " << this->_name;
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

void    FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->_name << " highs fives!";
}