#include "Movies.h"
#include <iostream>
#include <cstring>
#include <vector>

Movie::Movie() { //call the input
  promptInput();
}

Movie::Movie(char* title, int year, char* director, int duration, float rating) {
    setTitle(title);
    setYear(year);
    setDirector(director);
    setDuration(duration);
    setRating(rating);
}

void Movie::setDirector(char* director) {
    strcpy(this->director, director);
}

void Movie::setDuration(int duration) { //enter as an int (minutes)
    this->duration = duration;
}

void Movie::setRating(float rating) {
    this->rating = rating;
}

char* Movie::getDirector() {
    return director;
}

int Movie::getDuration() {
    return duration;
}

float Movie::getRating() {
    return rating;
}

const char* Movie::getType() {
    return "Movie";
}

void Movie::print() { //print
    Media::print();
    cout << "Director: " << director << '\n';
    cout << "Duration: " << duration << '\n';
    cout << "Rating: " << rating << '\n';
}

void Movie::promptInput() { //input
    Media::promptInput();
    cout << "Enter director: ";
    cin.getline(director, 80);
    cout << "Enter duration: ";
    cin >> duration;
    cout << "Enter rating: ";
    cin >> rating;
    cin.ignore();
}
