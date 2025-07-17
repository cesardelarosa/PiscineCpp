#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << this->_name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	*this = copy;
	std::cout << "ClapTrap " << this->_name << " has been copied!" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->_name << " is destroyed!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	std::cout << "ClapTrap " << this->_name << " assignment operator called!"
			  << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string &target) {
	std::cout << "ClapTrap " << this->_name;
	if (this->_energyPoints == 0) {
		std::cout << " is out of energy and can't attack!" << std::endl;
		return;
	}
	if (this->_hitPoints == 0) {
		std::cout << " is broken and can't attack!" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << " attacks " << target << ", causing " << this->_attackDamage
			  << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->_name;
	if (this->_hitPoints == 0) {
		std::cout << " is already broken!" << std::endl;
		return;
	}
	if (this->_hitPoints < amount)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << " takes " << amount << " points of damage! " << this->_hitPoints
			  << " HP left." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << this->_name;
	if (this->_energyPoints == 0) {
		std::cout << " is out of energy and can't repair!" << std::endl;
		return;
	}
	if (this->_hitPoints == 0) {
		std::cout << " is broken and can't repair itself!" << std::endl;
		return;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << " repairs itself for " << amount << " hit points! Now has "
			  << this->_hitPoints << " HP." << std::endl;
}