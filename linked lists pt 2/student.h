#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class student {
public:
	int getID();
	void setID(int num);
	void setGPA(float grade);
	float getGPA();
	student(char* firstname, char* lastname, int id, float gpa);
	void print();
private:
	char firstname[35];
	char lastname[35];
	int id;
	float gpa;
};
#endif
