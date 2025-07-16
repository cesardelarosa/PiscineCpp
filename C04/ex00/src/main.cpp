#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_i = new WrongCat();

    meta->makeSound();
    j->makeSound();
    i->makeSound();
    wrong_meta->makeSound();
    wrong_i->makeSound();

    delete meta;
    delete j;
    delete i;
    delete wrong_meta;
    delete wrong_i;

    return 0;
}