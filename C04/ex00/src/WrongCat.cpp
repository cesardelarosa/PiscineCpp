#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat () : WrongAnimal()
{
    this->type = "WrongCat";
}

WrongCat::WrongCat (const WrongCat& copy) : WrongAnimal(copy)
{
    *this = copy;
}

WrongCat::~WrongCat ()
{
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
    if (this != &rhs)
        this->type = rhs.type;
    return *this;
}

void WrongCat::makeSound()
{
    std::cout << "MEOWWWW" << std::endl;
}