#pragma once
#include <string>

class Animal {

  public:
	Animal();
	Animal(const Animal &copy);
	virtual ~Animal();

	Animal &operator=(const Animal &rhs);

	virtual void makeSound() const;
	std::string getType() const;

  protected:
	std::string type;
};
