#pragma once
#include "cat.h"
#include <string>
#include <vector>

class Persian : public Cat {
public :
	Persian(std::string name, int age);
	Persian(std::string name, int age, std::vector<std::string> costumTraits);
	std::string displaySound() override;
	Persian(const Cat& nou);
	Persian& operator= (const Persian& nou);
};
