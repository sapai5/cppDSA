//variables for games

#pragma once
#include "Media.h"
#include <iostream>
#include <cstring>
#include <vector>

class Game : public Media {
private:
	char publisher[80];
	float rating;
public:
	Game();
	Game(char* title, int year, char* publisher, float rating);
	void setPublisher(char* publisher);
	void setRating(float rating);
	char* getPublisher();
	float getRating();
	const char* getType();
	void print();
	void promptInput();
};
