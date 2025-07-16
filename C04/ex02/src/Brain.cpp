#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& copy) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = copy;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs) {
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &rhs) {
        for (size_t i = 0; i < n_ideas; ++i) {
            this->ideas[i] = rhs.ideas[i];
        }
    }
    return *this;
}
