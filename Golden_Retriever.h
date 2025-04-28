#pragma once
#include "dog.h"
#include <string>
#include <vector>

class GoldenRetriever : public Dog {
public:
	GoldenRetriever(std::string name, int age);
	GoldenRetriever(std::string name, int age, std::vector<std::string> costumTraits);
	GoldenRetriever(const Dog& nou);
	GoldenRetriever& operator=(const GoldenRetriever& nou);

	std::string displaySound() override;
};
