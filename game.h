#pragma once
#include "Animal.h"
#include "dog.h"
#include "cat.h"
#include "button.h"
#include "SpeciesNotFoundException.h"

class Game {
	private:
		static int dogCount;
		static int catCount;
		std::vector<Animal*> animals;  
		std::vector<Dog*> dogs;  
		std::vector<Cat*> cats;  
		std::vector<std::string> dogBreeds = {
			"Golden Retriever", "Bulldog", "Poodle", "Bichon" };
		std::vector<std::string> catBreeds = {
			"Siamese", "Sfinx", "Persian" };
		mutable std::vector<Button> catBreedButtons;
		mutable std::vector<Button> dogBreedButtons;

	public:
		Game();
		void addAnimal(Animal* animal);
		void addDog(Dog* dog);
		void addCat(Cat* cat);
		void displayDogs() const;
		void displayCats() const;
		~Game();
		void displayDogsSpecies() const;
		void displayCatsSpecies() const;
		std::vector<Button> getDogBreedButtons() const;
		std::vector<Button> getCatBreedButtons() const;
		Animal* displayAnimalSpecies(const std::string nameSpecies) const;

		void displayAnimalSound(Animal* animal);
};

