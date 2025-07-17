#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap {
  public:
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap &operator=(const DiamondTrap &rhs);
	~DiamondTrap();

	void attack(const std::string &target);
	void whoAmI();

  private:
	std::string _name;
};