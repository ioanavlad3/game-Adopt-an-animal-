#pragma once
#include "AnimalException.h"

class InvalidAgeException : public AnimalException {
public:
	InvalidAgeException(int age);
};