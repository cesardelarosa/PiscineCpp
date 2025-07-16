#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("Generic WrongAnimal") {
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal (const WrongAnimal& copy) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = copy;
}

WrongAnimal::~WrongAnimal () {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if (this != &rhs)
        this->type = rhs.type;
    return *this;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "*WrongAnimal generic sound*" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}
