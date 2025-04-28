#pragma once
#include "dog.h"
#include <iostream>
#include <vector>
#include <string>

class Bulldog : public Dog {
public:
	Bulldog(std::string name, int age);
	Bulldog(std::string name, int age, std::vector<std::string> costomTraits);
	Bulldog(const Dog& nou);
	Bulldog& operator=(const Bulldog& nou);
	std::string displaySound() override;
};