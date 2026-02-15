#pragma once
#include "Cufar.h"
#include <string>

class CufarFactory{
public:
	static Cufar<int> creazaCufarBonus(){
		// o suma de bani intre 100 si 400
		int bani = rand() % 300 + 100;
		return Cufar<int>(bani, "coins");
	}
	static Cufar<int> creazaCufarSanatate() {
		int sanatate = rand() % 100 + 1;
		return Cufar<int>(sanatate, "health");
	}
	static Cufar<int> creazaCufarFericire() {
		int fericire = rand() % 50 + 1;
		return Cufar<int>(fericire, "happiness");
	}
	static Cufar<int> creazaCufarEnergie() {
		int energie = rand() % 100 + 1;
		return Cufar<int>(energie, "energy");
	}
	static Cufar<std::string> creazaCufarQuote(std::string quote) {
		return Cufar<std::string>(quote, "quote");
	}

};