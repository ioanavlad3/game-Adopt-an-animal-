#pragma once
#include <exception>
#include <string>

class AnimalException : public std::exception {
protected:
	std::string message;
public:
	AnimalException();
	AnimalException(std::string message);
	virtual const char* what() const;
};