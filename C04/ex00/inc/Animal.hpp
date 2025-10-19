#pragma once

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

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

#endif