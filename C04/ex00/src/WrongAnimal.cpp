#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal ()
{
}

WrongAnimal::WrongAnimal (const WrongAnimal& copy)
{
    *this = copy;
}

WrongAnimal::~WrongAnimal ()
{
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
    if (this != &rhs)
        this->type = rhs.type;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "*WrongAnimal generic sound*" << std::endl;
}