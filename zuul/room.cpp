#include "room.h"
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

void room::setDescription(char* newDescription) {
	description = new char[100];
	strcpy(description, newDescription);
}

char* room::getDescription() {
	return description;
}

void room::setMap(map<char*, room*>* newExits) {
	exits = new map<char*, room*>;
	exits = newExits;
}

map<char*, room*>* room::getMap() {
	return exits;
}

void room::setTitle(char* newTitle) {
	title = new char[80];
	strcpy(title, newTitle);
}

char* room::getTitle() {
	return title;
}