#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
	std::cout << "--- Correct Animal ---" << std::endl;
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	delete j;
	delete i;

	std::cout << "\n--- Deep copy test ---" << std::endl;
	Dog dog;
	{
		Dog tmp = dog;
	}

	std::cout << "\n--- Animal array test ---" << std::endl;
	const int num_animals = 4;
	Animal *animals[num_animals];

	for (int k = 0; k < num_animals; ++k) {
		if (k < num_animals / 2) {
			animals[k] = new Dog();
		} else {
			animals[k] = new Cat();
		}
	}

	for (int k = 0; k < num_animals; ++k) {
		animals[k]->makeSound();
	}

	for (int k = 0; k < num_animals; ++k) {
		delete animals[k];
	}

	std::cout << "\n--- Wrong Animal ---" << std::endl;
	const WrongAnimal *meta = new WrongAnimal();
	const WrongAnimal *wcat = new WrongCat();

	std::cout << "\nmeta is a " << meta->getType() << std::endl;
	std::cout << "wcat is a " << wcat->getType() << std::endl;

	std::cout << "meta->makeSound(): ";
	meta->makeSound();
	std::cout << "wcat->makeSound(): ";
	wcat->makeSound();

	delete meta;
	delete wcat;

	return 0;
}
