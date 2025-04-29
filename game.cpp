#include "game.h"
#include <iostream>
#include <vector>
#include "raylib.h"

Game::Game() {}

void Game::addAnimal(Animal* animal) {
	if (animal->getName() != "Unknown") {
		this->animals.push_back(animal);
		if (dynamic_cast<Dog*>(animal)) {	// verific daca animalul este de tip Dog
			this->dogs.push_back(dynamic_cast<Dog*>(animal));
			dogCount++;
		}
		else if (dynamic_cast<Cat*>(animal)) {  
			this->cats.push_back(dynamic_cast<Cat*>(animal));
			catCount++;
		}
		else {
			if (animal)
				SpeciesNotFoundException e(animal->getSpecies());
		}
	}
}
	

void Game::addDog(Dog* dog) {
	this->dogs.push_back(dog);
	dogCount++;
}

void Game::addCat(Cat* cat) {
	this->cats.push_back(cat);
	catCount++;
}
void Game::displayDogs() const{
	for (const auto d : this->dogs)
	{
		d->display();
		std::cout << std::endl;
	}
}
void Game::displayCats() const{
	for (const auto& c : this->cats)
	{
		c->display();
		std::cout << std::endl;
	}
}

void Game::displayDogsSpecies() const {
	if (dogBreedButtons.empty()) {
		const int startY = 200;
		for (int i = 0; i < dogBreeds.size(); i++) {
			std::string breed = dogBreeds[i];
			Button B_breed(breed, 200, startY + i * 60, 200, 40);
			dogBreedButtons.push_back(B_breed);
		}
	}

	for (auto& btn : dogBreedButtons) {
		btn.Draw();
	}
}

void Game::displayCatsSpecies() const {
	if (catBreedButtons.empty()) {
		const int startY = 200;
		for (int i = 0; i < catBreeds.size(); i++) {
			std::string breed = catBreeds[i];
			Button B_breed(breed, 200, startY + i * 60, 200, 40);
			catBreedButtons.push_back(B_breed);
		}
	}

	for (auto& btn : catBreedButtons) {
		btn.Draw();
	}
}

Animal* Game::displayAnimalSpecies(const std::string nameSpecies)  const{
	DrawText(nameSpecies.c_str(), 190, 200, 20, PURPLE);
	int startY = 230;
	int i = 0;
	for (auto* a : this->animals) {
		if (a->getSpecies() == nameSpecies) {
			std::string caracteristics = a->display2();
			Button B_breed(caracteristics, 100, startY + i, 600, 65);
			B_breed.Draw();
			i += 70;
			if (B_breed.isPressed()) {
				return a;
			}
		}
	}
	return nullptr;
}

std::vector<Button> Game::getCatBreedButtons() const {
	return catBreedButtons;
}

std::vector<Button> Game::getDogBreedButtons() const {
	return dogBreedButtons;
}

void Game::displayAnimalSound(Animal* animal) {
	DrawText(animal->displaySound().c_str(), 190, 300, 20, PURPLE);  
}

Game::~Game() {}