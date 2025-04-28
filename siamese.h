#pragma once
#include "cat.h"
#include <string>


class Siamese : public Cat {
	public :
		Siamese(std::string name, int age);
		Siamese(const Cat& nou);
		Siamese& operator = (const Siamese& nou);
		//void makeSound() override;
};
