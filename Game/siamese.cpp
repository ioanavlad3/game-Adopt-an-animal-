#include "siamese.h"
#include <iostream>

Siamese::Siamese(std::string name, int age) : Cat(name, age) {
	this->species = "Siamese";
	this->traits.push_back("Vocal");
};

Siamese::Siamese(const Cat& nou) : Cat(nou) {
	this->species = "Siamese";
	this->traits.push_back("Vocal");
};

Siamese& Siamese::operator=(const Siamese& nou) {
	if (this != &nou) {
		this->name = nou.name;
		this->species = nou.species;
		this->isAdopted = nou.isAdopted;
		this->age = nou.age;
		this->size = nou.size;
		this->traits = nou.traits;
	}
	return *this;
}

std::string Siamese::displaySound() {
	return this->name + " says: Mrrrr";
}