#pragma once
#include <iostream>
#include <sstream>
#include <string>

template <typename T>
class Cufar {
	T continut;
	std::string tip;
public: 
	Cufar(T c, std::string t) : continut(c), tip(t) {}
	T getContinut() const {
		return this->continut;
	}
	std::string getTip() const {
		return this->tip;
	}
	void drawContinut(int poz_Y) const {
		std::ostringstream ss;
		ss << this->continut;
		DrawText(ss.str().c_str(), 700, poz_Y, 30, DARKPURPLE);
	}
};