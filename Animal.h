#pragma once  
#include <string>  
#include <vector>  


class Animal {
protected:
    std::string name;
    std::string species;
    bool isAdopted;
    int age;
    std::string size;
    std::vector<std::string> traits;

public:
    Animal();
    Animal(std::string name, std::string species, bool isAdopted, int age, std::string size, std::vector<std::string> traits);
    Animal(const Animal& nou);
    Animal& operator=(const Animal& nou);
    virtual ~Animal();

    virtual void makeSound() = 0;
    virtual std::string displaySound() = 0;
    virtual void display() const; 
	virtual std::string getSpecies() const;

    virtual std::string display2() const;  // returneaza string cu caracteristicile unui obiect 
    virtual std::string getName() const;
   // virtual std::string getS() const;
	virtual void setAdopted();

};