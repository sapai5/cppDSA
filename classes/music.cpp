#include "Music.h"
#include <iostream>
#include <cstring>
#include <vector>

Music::Music() {
  promptInput();
}

Music::Music(char* title, int year, char* artist, int duration, char* publisher) {
    setTitle(title);
    setYear(year);
    setArtist(artist);
    setDuration(duration);
    setPublisher(publisher);
}

void Music::setArtist(char* artist) {
    strcpy(this->artist, artist);
}

void Music::setDuration(int duration) {
    this->duration = duration;
}

void Music::setPublisher(char* publisher) {
    strcpy(this->publisher, publisher);
}

char* Music::getArtist() {
    return artist;
}

int Music::getDuration() {
    return duration;
}

char* Music::getPublisher() {
    return publisher;
}

const char* Music::getType() {
    return "Music";
}

void Music::print() {
    Media::print();
    cout << "Artist: " << artist << '\n';
    cout << "Duration: " << duration << '\n';
    cout << "Publisher: " << publisher << '\n';
}

void Music::promptInput() {
    Media::promptInput();
    cout << "Enter artist: ";
    cin.getline(artist, 80);
    cout << "Enter duration: ";
    cin >> duration;
    cin.ignore();
    cout << "Enter publisher: ";
    cin.getline(publisher, 80);
}
