#include "EmptyNameException.h"
#include <iostream>

EmptyNameException::EmptyNameException() :
	AnimalException("The name of the animal is empty!") {}