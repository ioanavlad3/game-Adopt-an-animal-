#include "cat.h"
#include <iostream>

Cat::Cat(std::string name, int age) : 
	Animal(name, "Cat", false, age, "Small", {"Possesive"}) {
	if (age < 0) throw InvalidAgeException(age);
	if (name == "") throw EmptyNameException();
}

Cat::Cat(std::string name, int age, std::vector<std::string> costumTraits) :
	Animal(name, "Cat", false, age, "Small", { "Possesive" }) {
	if (age < 0) throw InvalidAgeException(age);
	if (name == "") throw EmptyNameException();
	//this->traits.push_back("Possesive");
	for (const auto& t : costumTraits) {
		this->traits.push_back(t);
	}
}

Cat::Cat() : Animal("Unknown", "Cat", false, 0, "Unknown", { "Unknown" }) {
	this->name = "Unknown";
	this->species = "Cat";
	this->isAdopted = false;
	this->age = 0;
	this->size = "Unknown";
	this->traits = { "Unknown" };
}

Cat::Cat(const Cat& nou) : Animal(nou) {
	this->name = nou.name;
	this->species = nou.species;
	this->isAdopted = nou.isAdopted;
	this->age = nou.age;
	this->size = nou.size;
	this->traits = nou.traits;
}

Cat& Cat::operator=(const Cat& nou) {
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

void Cat::makeSound(){
    std::cout << name << " says: Miau Miau!\n";
}

std::string Cat::displaySound() {
	return name + " says: Miau Miau!";
}

Cat Cat::createCatSafe(const std::string& name, int age) {
	try {
		Cat c(name, age);
		return c;
	}
	catch (const AnimalException& e) {
		std::cerr << "Error creating Cat: " << e.what() << std::endl;
		return Cat();
	}
}

Cat Cat::createCatSafe(const std::string& name, int age, 
				const std::vector<std::string> costumTraits) {
	try {
		Cat c(name, age, costumTraits);
		return c;
	}
	catch (const AnimalException& e) {
		std::cerr << "Error creating Cat: " << e.what() << std::endl;
		return Cat();
	}
}
