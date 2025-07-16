#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Generic Animal")
{
}

Animal::Animal (const Animal& copy)
{
    *this = copy;
}

Animal::~Animal ()
{
}

Animal& Animal::operator=(const Animal& rhs)
{
    if (this != &rhs)
        this->type = rhs.type;
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "*Animal generic sound*" << std::endl;
}