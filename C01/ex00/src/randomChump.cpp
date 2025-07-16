 #include "Zombie.hpp"

void    randomChump(std::string name)
{
    Zombie  stack_zombie;
    stack_zombie.setName(name);
    stack_zombie.announce();
}
