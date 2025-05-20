#include "Statistici.h"
#include <iostream>
#include <string>
#include <raylib.h>

Statistici::Statistici(int f, int s, int e) : 
	fericire(f), sanatate(s), energie(e) {}
void Statistici::modificaFericire(const int valoare) {
	this->fericire += valoare;
	if (this->fericire > 50)
		this->fericire = 50;
	if (this->fericire < 0)
		this->fericire = 0;
}
void Statistici::modificaSanatate(const int valoare) {
	this->sanatate += valoare;
	if (this->sanatate > 100)
		this->sanatate = 100;
	if (this->sanatate < 0)
		this->sanatate = 0;
}
void Statistici::modificaEnergie(const int valoare) {
	this->energie += valoare;
	if (this->energie > 100)
		this->energie = 100;
	if (this->energie < 0)
		this->energie = 0;
}

void Statistici::afisare(const int poz_Y) const {
	std::string text = "Happiness: " + std::to_string(this->fericire) + "  " + 
		"Health: " + std::to_string(this->sanatate) + "  " + 
		"Hungry: " + std::to_string(this->energie);
	DrawText(text.c_str(), 250, poz_Y, 30, BLACK);
}

int Statistici::getFericire() const {
	return this->fericire;
}
int Statistici::getEnergie() const {
	return this->energie;
}
int Statistici::getSanatate() const {
	return this->sanatate;
}

Statistici& Statistici::getInstance() {
	static Statistici instance;
	return instance;
}