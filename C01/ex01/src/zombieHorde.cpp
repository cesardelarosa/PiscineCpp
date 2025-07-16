#include "Zombie.hpp"
#include <iostream>

Zombie  *zombieHorde(int N, std::string name)
{
    if (N <= 0)
    {
        std::cerr << "Error: N must be greater than 0." << std::endl;
        return (0);
    }
    Zombie  *horde = new Zombie[N];
    for (int i = 0; i < N; i++)
        horde[i].setName(name);
    return horde;
}