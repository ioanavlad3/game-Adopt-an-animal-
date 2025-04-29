#pragma once
#include "button.h"
#include <iostream>

Button::Button(std::string text, int x, int y, int width, int height) {
	this->text = text;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}
void Button::Draw() const {
	DrawRectangle(this->x, this->y, this->width, this->height, LIGHTGRAY);
	const char* text = this->text.c_str();
	DrawText(text, this->x + 10, this->y + 10, 20, BLACK);
}

std::string Button::getText() const {
	return this->text;
}

std::string Button::transformText(const std::string text) {
	std::string transformedText = text;
	for (char c : transformedText) {
		c = toupper(c);
	}
	return transformedText;
}

bool Button::IsMouseOver() const {
	Vector2 mousePos = GetMousePosition();
	return (mousePos.x >= this->x && mousePos.x <= this->x + this->width &&
		mousePos.y >= this->y && mousePos.y <= this->y + this->height);
}

bool Button::isPressed() const {
	return IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && IsMouseOver();
}