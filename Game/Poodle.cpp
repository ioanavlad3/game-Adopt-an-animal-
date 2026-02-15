#include "Poodle.h"
#include <iostream>

Poodle::Poodle(std::string name, int age) : Dog(name, age, "Medium"){
    this->species = "Poodle";
    this->traits.push_back("Elegance"); 
}
Poodle::Poodle(std::string name, int age, std::vector<std::string> costomTraits) : 
    Dog(name, age, "Medium"){
    this->species = "Poodle";
    this->traits.push_back("Elegance");
    for (const auto& t : costomTraits){
        this->traits.push_back(t);
    }
}

Poodle::Poodle(const Dog& nou) : Dog(nou) {
	this->species = "Poodle";
	this->traits.push_back("Elegance");
}

Poodle& Poodle::operator=(const Poodle& nou) {
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