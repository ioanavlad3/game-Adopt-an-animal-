#include "SpeciesNotFoundException.h"
#include <iostream>

SpeciesNotFoundException::SpeciesNotFoundException(std::string species) :
	AnimalException("Species not found: " + species) {}