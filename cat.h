#pragma once
#include "Animal.h"
#include "AnimalException.h"
#include "InvalidAgeException.h"
#include "EmptyNameException.h"

class Cat : public Animal {
    public:
        Cat(std::string name, int age);
        Cat();
		Cat(std::string name, int age, std::vector<std::string> costumTraits);
		Cat(const Cat& nou);
		Cat& operator=(const Cat& nou);
        void makeSound() override;
		std::string displaySound() override;
		virtual Cat createCatSafe(const std::string& name, int age);
		virtual Cat createCatSafe(const std::string& name, int age, 
							const std::vector<std::string> costumTraits);
};