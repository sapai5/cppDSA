#include "student.h"
#include <cstring>
#include <iomanip>

using namespace std;

student::student(char* firstname, char* lastname, int id, float gpa) {
	strcpy_s(this->firstname, firstname);
	strcpy_s(this->lastname, lastname);
	this->id = id;
	this->gpa = gpa;
}

void student::setID(int studentNum) {
	id = studentNum;
}

int student::getID() {
	return id;
}

void student::setGPA(float grade) {
	gpa = grade;
}

float student::getGPA() {
	return gpa;
}

void student::print() {
	cout << "[" << id << "] " << firstname << " " << lastname << " (" << fixed << setprecision(2) << gpa << ")\n";
}
