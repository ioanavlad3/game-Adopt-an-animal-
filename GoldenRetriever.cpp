#include <iostream>
#include "Golden_Retriever.h"

GoldenRetriever::GoldenRetriever(std::string name, int age) : Dog(name, age, "Big") {
	this->species = "Golden Retriever";
	this->traits.push_back("Good with kids");
}

GoldenRetriever::GoldenRetriever(std::string name, int age, 
	std::vector<std::string> costumTraits) : Dog(name, age, "Big") {
	this->species = "Golden Retriever";
	this->traits.push_back("Good with kids");
	for (const auto& t : costumTraits) {
		this->traits.push_back(t);
	}
}

GoldenRetriever::GoldenRetriever(const Dog& nou) : Dog(nou) {
	this->species = "Golden Retriever";
	this->traits.push_back("Good with kids");
}

GoldenRetriever& GoldenRetriever::operator=(const GoldenRetriever& nou) {
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


std::string GoldenRetriever::displaySound() {
	return this->name + " says: Woof Woof!";
}