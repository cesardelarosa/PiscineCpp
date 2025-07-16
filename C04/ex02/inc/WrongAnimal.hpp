#pragma once
#include <string>

class   WrongAnimal {

    public: 
        WrongAnimal();
        WrongAnimal(const WrongAnimal& copy);
        ~WrongAnimal();

        WrongAnimal& operator = (const WrongAnimal& rhs);
        
        void    makeSound(void) const;
        std::string getType(void) const;

    protected:
        std::string type;
};
