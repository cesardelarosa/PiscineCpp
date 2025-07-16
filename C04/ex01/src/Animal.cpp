#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Generic Animal") {
  std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) {
  std::cout << "Animal copy constructor called" << std::endl;
  *this = copy;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

Animal &Animal::operator=(const Animal &rhs) {
  std::cout << "Animal assignment operator called" << std::endl;
  if (this != &rhs)
    this->type = rhs.type;
  return *this;
}

void Animal::makeSound() const {
  std::cout << "*Animal generic sound*" << std::endl;
}

std::string Animal::getType() const { return this->type; }
