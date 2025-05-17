#pragma once
class Statistici {
private:
	int fericire;
	int sanatate;
	int energie;
	Statistici (int f = 20, int s = 30, int e = 35);
public:
	Statistici(const Statistici&) = delete;
	Statistici& operator=(const Statistici&) = delete;

	static Statistici& getInstance();

	void modificaFericire(const int valoare);
	void modificaSanatate(const int valoare);
	void modificaEnergie(const int valoare);
	void afisare(int poz_Y = 100);

	int getFericire() const;
	int getSanatate() const;
	int getEnergie() const;

};