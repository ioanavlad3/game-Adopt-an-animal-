#include <iostream>
#include "Sfinx.h"

Sfinx::Sfinx(std::string name, int age) : Cat(name, age) {
	this->species = "Sfinx";
	this->traits.push_back("Hairless");
	this->traits.push_back("Intelligent");
};
Sfinx::Sfinx(std::string name, int age, std::vector<std::string> costumTraits) 
	: Cat(name, age) {
	this->species = "Sfinx";
	this->traits.push_back("Hairless");
	for (const auto& t : costumTraits) {
		this->traits.push_back(t);
	}
}

Sfinx::Sfinx(const Cat& nou) : Cat(nou) {
	this->species = "Sfinx";
	this->traits.push_back("Hairless");
	this->traits.push_back("Intelligent");
}

Sfinx& Sfinx::operator=(const Sfinx& nou) {
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