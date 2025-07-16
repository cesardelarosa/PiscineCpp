#pragma once
#include <string>

class   Animal {

    public: 
        Animal();
        Animal(const Animal& copy);
        virtual ~Animal();

        Animal& operator = (const Animal& rhs);

        virtual void    makeSound(void) const;
        std::string     getType(void) const;

    protected:
        std::string type;
};
