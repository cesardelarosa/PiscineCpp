#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() { this->type = "Cat"; }

Cat::Cat(const Cat &copy) : Animal(copy) { *this = copy; }

Cat::~Cat() {}

Cat &Cat::operator=(const Cat &rhs) {
  if (this != &rhs)
    this->type = rhs.type;
  return *this;
}

void Cat::makeSound() const { std::cout << "MEOWWWW" << std::endl; }