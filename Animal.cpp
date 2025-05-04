#include "Animal.h"
#include <iostream>

Animal::Animal() : name(""), species(""), isAdopted(false), age(0), size(""), traits(){}

Animal::Animal(std::string name, std::string species, bool isAdopted, int age, 
    std::string size, std::vector<std::string> traits) {
    this->name = name;
    this->species = species;
    this->isAdopted = isAdopted;
    this->age = age;
    this->size = size;
    this->traits = traits;
}

Animal::Animal(const Animal &nou) {
    this->name = nou.name;
    this->species = nou.species;
    this->isAdopted = nou.isAdopted;
    this->age = nou.age;
    this->size = nou.size;
    this->traits = nou.traits;
}

Animal &Animal::operator=(const Animal &nou) {
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

Animal::~Animal() {}

void Animal::display() const{
    std::cout << "Name: " << this->name << "\t";
    std::cout << "Species: " << this->species << "\t";
    std::cout << "Adopted: " << (this->isAdopted ? "Yes" : "No") << "\t";
    std::cout << "Age: " << this->age << "\t";
    std::cout << "Size: " << this->size << "\n";

    for (const auto& trait : this->traits){
        std::cout << trait << " ";
    }
    std::cout << "\n";
}


std::string Animal::display2() const {
    std::string caracteristics = "Caracteristics: ";
    for (const auto& t : this->traits) {
        caracteristics += t + " ";
    }
    return "Name:\t" + this->name + ",\tAge: " + std::to_string(this->age) + ",\tSize: " + this->size
        + "\n" + caracteristics;
}

std::string Animal::getSpecies() const {
	return this->species;
}

std::string Animal::getName() const {
    return this->name;
}

void Animal::setAdopted() {
	this->isAdopted = true;
}

//std::string Animal::getS() const {
//    return this->species;
//}