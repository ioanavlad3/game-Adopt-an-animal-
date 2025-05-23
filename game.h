#pragma once
#include "Animal.h"
#include "dog.h"
#include "cat.h"
#include "button.h"
#include "SpeciesNotFoundException.h"
#include "Circle.h"

class Game {
	private:
		static int dogCount;
		static int catCount;
		int coins = 0;
		std::vector<Animal*> animals;  
		std::vector<Dog*> dogs;  
		std::vector<Cat*> cats;  
		std::vector<std::string> dogBreeds = {
			"Golden Retriever", "Bulldog", "Poodle", "Bichon" };
		std::vector<std::string> catBreeds = {
			"Siamese", "Sfinx", "Persian" };
		mutable std::vector<Button> catBreedButtons;
		mutable std::vector<Button> dogBreedButtons;
		mutable std::vector<Rectangle> obstacles;
		mutable std::vector<Vector2> obstacleVelocities;

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

		int randomNumber(int min, int max) const;
		void displayRandomObstacles() const;

		void displayAnimalSound(Animal* animal);
		bool checkColl(const Rectangle playerRec) const;
		void generateObstacles(Vector2 playerPos, float playerWidth, float playerHeight);

		bool isEmptyObstacles() const;
		void clearObstacles() const;
		void updateObstacles(const Rectangle goals[]) const;

		void addCoins(const int points);
		int getCoins() const;
		
		std::string boyOrGirl(const std::string name) const;
};

