#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  const WrongAnimal *wrong_meta = new WrongAnimal();
  const WrongAnimal *wrong_i = new WrongCat();

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