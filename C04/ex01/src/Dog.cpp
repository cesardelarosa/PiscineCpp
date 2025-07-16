#include "Dog.hpp"
#include <iostream>

Dog::Dog () : Animal() {
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog (const Dog& copy) : Animal(copy) {
    this->brain = new Brain(*copy.brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog () {
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &rhs){
        Animal::operator=(rhs);
        delete this->brain;
        this->brain = new Brain(*rhs.brain);
    }
    return *this;
}

void Dog::makeSound(void) const
{
    std::cout << "WWWWOUGH" << std::endl;
}
