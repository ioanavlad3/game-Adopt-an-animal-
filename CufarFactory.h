#pragma once
#include "Cufar.h"

class CufarFactory{
public:
	static Cufar<int> creazaCufarBonus(){
		// o suma de bani intre 100 si 400
		int bani = rand() % 300 + 100;
		return Cufar<int>(bani, "coins");
	}
	static Cufar<int> creazaCufarSanatate() {
		int sanatate = rand() % 100 + 1;
		return Cufar<int>(sanatate, "sanatate");
	}
	static Cufar<int> creazaCufarFericire() {
		int fericire = rand() % 50 + 1;
		return Cufar<int>(fericire, "fericire");
	}
	static Cufar<int> creazaCufarEnergie() {
		int energie = rand() % 100 + 1;
		return Cufar<int>(energie, "energie");
	}

};