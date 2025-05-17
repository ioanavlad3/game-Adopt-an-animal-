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
		const int startY = 300;
		for (int i = 0; i < dogBreeds.size(); i++) {
			std::string breed = dogBreeds[i];
			Button B_breed(breed, 700, startY + i * 60, 200, 40);
			dogBreedButtons.push_back(B_breed);
		}
	}

	for (auto& btn : dogBreedButtons) {
		btn.Draw();
	}
}

void Game::displayCatsSpecies() const {
	if (catBreedButtons.empty()) {
		const int startY = 300;
		for (int i = 0; i < catBreeds.size(); i++) {
			std::string breed = catBreeds[i];
			Button B_breed(breed, 700, startY + i * 60, 200, 40);
			catBreedButtons.push_back(B_breed);
		}
	}

	for (auto& btn : catBreedButtons) {
		btn.Draw();
	}
}

Animal* Game::displayAnimalSpecies(const std::string nameSpecies)  const{
	DrawText(nameSpecies.c_str(), 620, 200, 50, BLACK);
	int startY = 260;
	int i = 0;
	for (auto* a : this->animals) {
		if (a->getSpecies() == nameSpecies) {
			std::string caracteristics = a->display2();
			Button B_breed(caracteristics, 500, startY + i, 600, 65);
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
	DrawText(animal->displaySound().c_str(), 1000, 300, 30, PURPLE);  
}

Game::~Game() {}

int Game::randomNumber(int min, int max) const {
	return min + rand() % (max - min + 1); 
}

void Game::displayRandomObstacles() const {
	for (auto& obst : obstacles) {
		//DrawRectangleRec(obst, RED);
		DrawCircle(obst.x, obst.y, 20, RED);
	}
}

bool Game::checkColl(const Rectangle playerRec) const {
	for (const auto& obst : obstacles) {
		if (CheckCollisionRecs(playerRec, obst)) {
			return true;
		}
	}
	return false;
}

void Game::generateObstacles(Vector2 playerPos, float playerWidth, float playerHeight) {
	int numberObstacles = randomNumber(5, 10);
	obstacles.clear();

	Rectangle playerRec = { playerPos.x /*+ 25*/, playerPos.y /*+ 15*/, playerWidth, playerHeight };

	int generated = 0;
	int minX = 200;
	int maxX = 300;
	const int minY = 180;
	const int maxY = 600;

	while (generated < numberObstacles) {
		Rectangle aux = { randomNumber(minX, maxX), randomNumber(minY, maxY), 20, 20 };
		

		bool overlaps = false;
		for (const auto& obst : obstacles) {
			if (CheckCollisionRecs(aux, obst)) {
				overlaps = true;
				break;
			}
			//if (CheckCollisionCircleV(obst.center, obst.radius, obst))
		}
		
		if ((aux.x < playerRec.x - 100 || aux.x > playerRec.x + 100) &&
			(aux.y < playerRec.y - 100 || aux.y > playerRec.y + 100) && 
			!overlaps) {
			obstacles.push_back(aux);

			float velX = randomNumber(-100, 100) / 60.0f; 
			float velY = randomNumber(-100, 100) / 60.0f;
			obstacleVelocities.push_back({ velX, velY });

			generated++;
			minX += 150;
			maxX += 300;
			
		}
	}
}

bool Game::isEmptyObstacles() const {
	return obstacles.empty();
}

void Game::clearObstacles() const {
	this->obstacles.clear();
}

void Game::updateObstacles(const Rectangle goals[]) const {
	for (int i = 0; i < obstacles.size(); i++) {
		obstacles[i].x += obstacleVelocities[i].x;
		obstacles[i].y += obstacleVelocities[i].y;

		// daca se loveste de un cufar sa il ocoleasca
		for (int j = 0; j < 4; j ++) {
			if (CheckCollisionRecs(obstacles[i], goals[j])) {
				obstacleVelocities[i].x *= -1;
				obstacleVelocities[i].y *= -1;
			}
		}
		// sa nu iasa din ecran
		if (obstacles[i].x < 0 || obstacles[i].x + obstacles[i].width >= 1600) {
			obstacleVelocities[i].x *= -1;
		}
		if (obstacles[i].y < 0 || obstacles[i].y + obstacles[i].height >= 800) {
			obstacleVelocities[i].y *= -1;
		}

	}
}

void Game::addCoins(const int points) {
	this->coins += points;
}

int Game::getCoins() const{
	return this->coins;
}

std::string Game::boyOrGirl(const std::string name) const {
	if (!name.empty()) {
		char lastChar = name.back(); 

		if ((lastChar == 'a' && (name != "Mihnea" && name != "mihnea")) ||
			(name == "Carmen" || name == "carmen" || 
			 name == "Yasmin" || name == "yasmin")) {
			return "girl";
		}
	}

	return "boy";

}