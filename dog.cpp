#include "dog.h"
#include <iostream>

// cand se face o instanta Dog se apeleaza constructorul de la Animal
Dog::Dog(std::string name, int age, std::string size)
    : Animal(name, "Dog", false, age, size, {"Loyal", "Energetic"}) {
	if (age < 0) throw InvalidAgeException(age);
	if (name == "") throw EmptyNameException();
}

//default constructor
Dog::Dog() : Animal("Unknown", "Dog", false, 0, "Unknown", { "Unknown" }) {
	this->name = "Unknown";
	this->species = "Dog";
	this->isAdopted = false;
	this->age = 0;
	this->size = "Unknown";
	this->traits = { "Unknown" };
}

Dog::Dog(std::string name, int age, std::string size,
		const std::vector<std::string> costumTraits) 
		: Animal(name, "Dog", false, age, size, { "Loyal", "Energetic" }) {
	if (age < 0) throw InvalidAgeException(age);
	if (name == "") throw EmptyNameException();
	for (const auto& t : costumTraits) {
		this->traits.push_back(t);
	}
}

Dog::Dog(const Dog& nou) : Animal(nou) {
	this->name = nou.name;
	this->species = nou.species;
	this->isAdopted = nou.isAdopted;
	this->age = nou.age;
	this->size = nou.size;
	this->traits = nou.traits;
}

Dog& Dog::operator=(const Dog& nou) {
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

void Dog::makeSound() {
    std::cout << name << " says: HAM - HAM!\n";
}

std::string Dog::displaySound() {
	return name + " says: HAM - HAM!";
}

std::string Dog::getSizeBySpecies(const std::string species) {
	if (species == "Bichon") {
		return "Small";
	}
	else if (species == "Poodle") {
		return "Medium";
	}
	else if (species == "Bulldog") {
		return "Small";
	}
	else if (species == "Golden Retriever") {
		return "Big";
	}
	else if (species == "Sfinx") {
		return "Small";
	}
	else if (species == "Siamese") {
		return "Small";
	}
	else if (species == "Persian") {
		return "Small";
	}
	else {
		return "Unknown"; 
	}
}

Dog Dog::createDogSafe(const std::string name, int age, const std::string species) {
	try {
		std::string size = getSizeBySpecies(species);
		Dog d(name, age, size);  
		return d;  
	}
	catch (const AnimalException& e) {
		std::cerr << "Error creating Dog: " << e.what() << std::endl;
		return Dog();
	}
}

Dog Dog::createDogSafe(const std::string name, int age, const std::string species,
			const std::vector<std::string> costumTraits) {
	try {
		std::string size = getSizeBySpecies(species);
		Dog d(name, age, size, costumTraits);
		return d;
	}
	catch (const AnimalException& e) {
		std::cerr << "Error creating Dog: " << e.what() << std::endl;
		return Dog();
	}
}