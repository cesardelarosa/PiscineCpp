#include "Serializer.hpp"
#include <iostream>

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define BOLD "\033[1m"

int main() {
	Data originalData;
	originalData.id = 42;
	originalData.name = "Test Object";
	originalData.value = 3.14159;

	std::cout << BOLD << BLUE << "\n=== SERIALIZATION TEST ===" << RESET
			  << std::endl;

	std::cout << "Original Object Address: " << GREEN << &originalData << RESET
			  << std::endl;
	std::cout << "Original Data: ID=" << originalData.id
			  << ", Name=" << originalData.name
			  << ", Value=" << originalData.value << std::endl;

	// Serialize
	uintptr_t raw = Serializer::serialize(&originalData);

	std::cout << "\n[Serialized to uintptr_t]: " << raw << " (Decimal address)"
			  << std::endl;

	// Deserialize
	Data *restoredPtr = Serializer::deserialize(raw);

	std::cout << "\n[Deserialized Address]:    " << GREEN << restoredPtr
			  << RESET << std::endl;

	return 0;
}
