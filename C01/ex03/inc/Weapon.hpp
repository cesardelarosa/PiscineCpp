#pragma once
#include <string>

class Weapon
{
    public:
    
        Weapon(std::string type);
        ~Weapon();

        const std::string    &getType(void);
        void           setType(std::string type);
    
    private:
        
        std::string _type;
};
