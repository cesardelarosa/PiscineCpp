#include "Dog.hpp"
#include <iostream>

Dog::Dog () : Animal()
{
    this->type = "Dog";
}

Dog::Dog (const Dog& copy) : Animal(copy)
{
    *this = copy;
}

Dog::~Dog ()
{
}

Dog& Dog::operator=(const Dog& rhs)
{
    if (this != &rhs)
        this->type = rhs.type;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "WWWWOUGH" << std::endl;
}