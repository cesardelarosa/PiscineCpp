#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name"),
	  FragTrap(name),
	  ScavTrap(name),
	  _name(name) {
	std::cout << "DiamondTrap " << this->_name << " constructor called" << std::endl;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
	: ClapTrap(copy),
	  FragTrap(copy),
	  ScavTrap(copy),
	  _name(copy._name) {
	std::cout << "DiamondTrap " << this->_name << " has been copied!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		ClapTrap::_name = rhs.ClapTrap::_name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	std::cout << "DiamondTrap " << this->_name << " assignment operator called!" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->_name << " is destroyed!" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "My DiamondTrap name is " << this->_name
			  << " and my ClapTrap name is " << ClapTrap::_name
			  << std::endl;
}