#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class   Dog: public Animal {
    
    public: 
        Dog();
        Dog(const Dog& copy);
        ~Dog();

        Dog& operator = (const Dog& rhs);
        
        void    makeSound(void) const;

    private:
        Brain*  brain;
};
