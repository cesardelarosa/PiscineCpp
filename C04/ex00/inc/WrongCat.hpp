#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

  public:
	WrongCat();
	WrongCat(const WrongCat &copy);
	~WrongCat();

	WrongCat &operator=(const WrongCat &rhs);

	void makeSound();

  protected:
	std::string type;
};
