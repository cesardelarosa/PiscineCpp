#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {

  public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &copy);
	~ScavTrap();

	ScavTrap &operator=(const ScavTrap &rhs);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void guardGate(void);
};