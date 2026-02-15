#pragma once
#include "Animal.h"
#include "InvalidAgeException.h"
#include "EmptyNameException.h"
#include "SpeciesNotFoundException.h"
#include "AnimalException.h"
#include <memory>

class Dog : public Animal {
    public:
        Dog(std::string name, int age, std::string size);
        Dog();
		Dog(std::string name, int age, std::string size, 
                    const std::vector<std::string> costumTraits);
        Dog(const Dog& nou);
		Dog& operator=(const Dog& nou);
        void makeSound() override;
		std::string displaySound() override;
        static std::string getSizeBySpecies(const std::string species);
		virtual Dog createDogSafe(const std::string name, 
                        int age, const std::string size);
		virtual Dog createDogSafe(const std::string name, int age, const std::string species,
			const std::vector<std::string> costumTraits);
};
