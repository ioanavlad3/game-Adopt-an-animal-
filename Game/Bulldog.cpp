#pragma once
#include "Bulldog.h"

Bulldog::Bulldog(std::string name, int age) : Dog(name, age, "Small") {
	this->species = "Bulldog";
	this->traits.push_back("Strong");
}

Bulldog::Bulldog(std::string name, int age, std::vector<std::string> costumTraits) :
	Dog(name, age, "Small") {
	this->species = "Bulldog";
	this->traits.push_back("Strong");
	for (const auto& t : costumTraits) {
		this->traits.push_back(t);
	}
}

Bulldog::Bulldog(const Dog& nou) : Dog(nou) {
	this->species = "Bulldog";
	this->traits.push_back("Strong");
}

Bulldog& Bulldog::operator=(const Bulldog& nou) {
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

std::string Bulldog::displaySound() {
	return this->name + " says: Boom Boom!";
}