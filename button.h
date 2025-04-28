#pragma once
#include "raylib.h"
#include <string>

class Button {
private:
	std::string text;
	int x, y, width, height;
public:
	Button(std::string text, int x, int y, int width, int height);
	void Draw() const;
	bool IsMouseOver() const;
	bool isPressed() const;
	std::string getText() const;
	std::string transformText(const std::string& text);
};