#pragma once
#include "cat.h"
#include <string>
#include <vector>

class Sfinx : public Cat {
public:
	Sfinx(std::string name, int age);
	Sfinx(std::string name, int age, std::vector<std::string> costumTraits);
	Sfinx(const Cat& nou);
	Sfinx& operator=(const Sfinx& nou);
};