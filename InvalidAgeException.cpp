#include "InvalidAgeException.h"
#include <iostream>

InvalidAgeException::InvalidAgeException(int age) :
	AnimalException("Invalid age: " + std::to_string(age)) {}