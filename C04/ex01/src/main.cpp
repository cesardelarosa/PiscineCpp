#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
	// --- Subject Main Test (Leaks) ---
	std::cout << "--- Subject Main Test ---" << std::endl;
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << std::endl;
	delete j; // should not create a leak (virtual ~Animal)
	delete i;

	// --- Animal Array Test ---
	std::cout << "\n--- Animal Array Test ---" << std::endl;
	const int num_animals = 4;
	Animal *animals[num_animals];

	std::cout << std::endl;
	for (int k = 0; k < num_animals; ++k) {
		if (k < num_animals / 2) {
			animals[k] = new Dog();
		} else {
			animals[k] = new Cat();
		}
		std::cout << "Created " << animals[k]->getType() << std::endl;
	}

	std::cout << std::endl;
	for (int k = 0; k < num_animals; ++k) {
		delete animals[k];
	}

	// --- Deep Copy Test ---
	std::cout << "\n--- Deep Copy Test ---" << std::endl;
	Dog basic;
	{
		std::cout << "(Entering scope...)" << std::endl;
		Dog tmp = basic;
		std::cout << "(Exiting scope... tmp destructor called)" << std::endl;
	}
	std::cout << "(Scope exited... basic destructor called)" << std::endl;

	// --- Wrong Animal Test (from ex00, ensuring no leaks) ---
	std::cout << "\n--- Wrong Animal Test (No Polymorphism) ---" << std::endl;
	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongI = new WrongCat();

	std::cout << std::endl;
	wrongMeta->makeSound();
	wrongI->makeSound(); // Calls WrongAnimal::makeSound()

	std::cout << std::endl;
	delete wrongMeta;
	delete (WrongCat *)wrongI; // Cast to avoid leak

	std::cout << std::endl;
	return 0;
}
