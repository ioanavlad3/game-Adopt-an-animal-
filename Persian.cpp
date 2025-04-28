#include "Persian.h"
#include <iostream>

Persian::Persian(std::string name, int age) : Cat(name, age) {
	this->species = "Persian";
	this->traits.push_back("Fluffy");
};
Persian::Persian(std::string name, int age, std::vector<std::string> costumTraits)
	: Cat(name, age) {
	this->species = "Persian";
	this->traits.push_back("Fluffy");
	for (const auto& t : costumTraits) {
		this->traits.push_back(t);
	}
}

std::string Persian::displaySound() {
	return this->name + " says: Meow Meow!";
}

Persian::Persian(const Cat& nou) : Cat(nou) {
	this->species = "Persian";
	this->traits.push_back("Fluffy");
}

Persian& Persian::operator=(const Persian& nou) {
	if (this != &nou) {
		this->name = nou.name;
		this->age = nou.age;
		this->species = nou.species;
		this->isAdopted = nou.isAdopted;
		this->size = nou.size;
		this->traits = nou.traits;
	}
	return *this;
}