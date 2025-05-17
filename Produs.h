#pragma once
#include <string>
#include <iostream>

template <typename T>

class Produs {
	std::string name;
	int price;
	T efect;

public:
	Produs(const std::string n, int p, T e) : name(n), price(p), efect(e) {}
	void aply(T& val) const {
		val += efect;
	}
	int getPrice() const {
		return this->price;
	}

};