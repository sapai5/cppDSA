#pragma once
#include "Media.h"
#include <iostream>
#include <cstring>
#include <vector>
class Music : public Media {
private:
    char artist[80];
    int duration;
    char publisher[80];
public:
    Music();
    Music(char* title, int year, char* artist, int duration, char* publisher);
    void setArtist(char* artist);
    void setDuration(int duration);
    void setPublisher(char* publisher);
    char* getArtist();
    int getDuration();
    char* getPublisher();
    const char* getType();
    void print();
    void promptInput();
};