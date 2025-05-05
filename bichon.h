#pragma once
#include "dog.h"

class Bichon : public Dog {
    public:
        Bichon(std::string name, int age);
      
        //copy constructor
        Bichon(const Dog& nou);
        Bichon& operator=(const Bichon& nou);
        void makeSound() override;
        std::string displaySound() override;
		std::string getSpecies() const;
		
};