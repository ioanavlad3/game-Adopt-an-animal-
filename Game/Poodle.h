#pragma once
#include "dog.h"

class Poodle : public Dog {
    public:
        Poodle(std::string name, int age);
        Poodle(std::string name, int age, std::vector<std::string> traits);
        Poodle(const Dog& nou);
        Poodle& operator=(const Poodle& nou);
};