#include "AnimalException.h"
#include <iostream>

AnimalException::AnimalException() {}

AnimalException::AnimalException(std::string message) {
	this->message = message;
}
const char* AnimalException::what() const {
	return this->message.c_str();
}
