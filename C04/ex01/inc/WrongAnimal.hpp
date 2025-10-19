#pragma once

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal {

  public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);
	~WrongAnimal(); // NOT virtual (as required by subject)
	WrongAnimal &operator=(const WrongAnimal &rhs);

	void makeSound() const; // NOT virtual (as required by subject)
	std::string getType() const;

  protected:
	std::string type;
};

#endif