#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
	// --- Correct Animals (Polymorphism Test) ---
	std::cout << "--- Correct Animals (Polymorphism Test) ---" << std::endl;
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << std::endl;
	std::cout << "j is type: " << j->getType() << std::endl;
	std::cout << "i is type: " << i->getType() << std::endl;

	std::cout << std::endl;
	i->makeSound(); // Should output cat sound (virtual)
	j->makeSound(); // Should output dog sound (virtual)
	meta->makeSound();

	std::cout << std::endl;
	delete meta;
	delete j; // Correctly calls ~Dog() then ~Animal()
	delete i; // Correctly calls ~Cat() then ~Animal()

	// --- Wrong Animals (No Polymorphism Test) ---
	std::cout << "\n--- Wrong Animals (No Polymorphism) ---" << std::endl;
	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongI = new WrongCat();

	std::cout << std::endl;
	std::cout << "wrongI is type: " << wrongI->getType() << std::endl;
	std::cout << "wrongMeta is type: " << wrongMeta->getType() << std::endl;

	std::cout << std::endl;
	wrongMeta->makeSound(); // Calls WrongAnimal::makeSound()
	wrongI->makeSound();	// Calls WrongAnimal::makeSound() (not virtual)

	std::cout << std::endl;
	delete wrongMeta;
	// delete wrongI; // This would cause a leak (~WrongCat not called)
	delete (WrongCat *)wrongI;

	std::cout << std::endl;
	return 0;
}