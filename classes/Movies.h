#pragma once
#include "Media.h"
#include <iostream>
#include <cstring>
#include <vector>

class Movie : public Media {
private:
    char director[80];
    int duration;
    float rating;
public:
    Movie();
    Movie(char* title, int year, char* director, int duration, float rating);
    void setDirector(char* director);
    void setDuration(int duration);
    void setRating(float rating);
    char* getDirector();
    int getDuration();
    float getRating();
    const char* getType();
    void print();
    void promptInput();
};