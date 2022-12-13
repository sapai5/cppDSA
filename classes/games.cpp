#include "Games.h"
#include <iostream>
#include <cstring>
#include <vector>

Game::Game() { //calls the input
  promptInput();
}

Game::Game(char* title, int year, char* publisher, float rating) {
    setTitle(title);
    setYear(year);
    setPublisher(publisher);
    setRating(rating);
}

void Game::setPublisher(char* publisher) {
    strcpy(this->publisher, publisher);
}

void Game::setRating(float rating) {
    this->rating = rating;
}

char* Game::getPublisher() {
    return publisher;
}

float Game::getRating() {
    return rating;
}

const char* Game::getType() {
    return "Videogame";
}

void Game::print() {
    Media::print();
    cout << "Publisher: " << publisher << '\n';
    cout << "Rating: " << rating << '\n';
}

void Game::promptInput() { //input
    Media::promptInput();
    cout << "Enter publisher: ";
    cin.getline(publisher, 80);
    cout << "Enter rating: ";
    cin >> rating;
    cin.ignore();
}
