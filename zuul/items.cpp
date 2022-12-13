#include <iostream>
#include <cstring>
#include "item.h"

using namespace std;

void item::setName(char* newName) {
	name = new char[80];
	strcpy(name, newName);
}

char* item::getName() {
	return name;
}

void item::setLocation(room* newLoc) {
	location = newLoc;
}

room* item::getLoc() {
	return location;
}