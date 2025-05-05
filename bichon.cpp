#include "bichon.h"
#include <iostream>

Bichon::Bichon(std::string name, int age) : Dog(name, age, "Small") {
    this->species = "Bichon";
    this->traits.push_back("Friendly");
    this->traits.push_back("Playful");
}

Bichon::Bichon(const Dog& nou) : Dog(nou) {
	this->species = "Bichon";
	this->traits.push_back("Friendly");
	this->traits.push_back("Playful");
}

Bichon& Bichon::operator= (const Bichon& nou) {
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

void Bichon::makeSound() {
    std::cout << this->name << " says: Yip Yip!\n";
}

std::string Bichon::displaySound() {
	return this->name + " says: Yip Yip!";
}

std::string Bichon::getSpecies() const {
	return this->species;
}

