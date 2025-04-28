#pragma once
#include "AnimalException.h"

class EmptyNameException : public AnimalException {
public:
	EmptyNameException();
};
