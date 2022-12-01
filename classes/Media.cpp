#include "media.h"
#include <iostream>
#include <cstring>
#include <vector>

Media::Media() {

}

Media::~Media() {
	cout << "Deleted " << title << " (" << year << ")\n";
}

void Media::setTitle(char* title) {
	strcpy(this->title, title);
}

void Media::setYear(int year) {
	this->year = year;
}

char* Media::getTitle() {
	return title;
}

int Media::getYear() {
	return year;
}

const char* Media::getType() {
	return "Media";
}

void Media::print() {
	cout << "Type: " << getType() << '\n';
	cout << "Title: " << title << '\n';
	cout << "Year: " << year << '\n';
}

void Media::promptInput() {
	cout << "Enter title: ";
	cin.getline(title, 100);
	cout << "Enter year: ";
	cin >> year;
	cin.ignore();
}