#pragma once
#include "AnimalException.h"

class SpeciesNotFoundException : public AnimalException {
public:
	SpeciesNotFoundException(std::string species);
};