#pragma once

#include <cstring>

struct Student
{
	char fName[40];
	char lName[40];
	unsigned int ID;
	float gpa;

	Student() {
		memset(this, 0x0, sizeof(Student)); //https://www.ibm.com/docs/en/i/7.1?topic=functions-memset-set-bytes-value
	}

	Student(Student* stu) {
		memcpy(this, stu, sizeof(Student));
	}

	Student(char* fName, char* lname, unsigned int ID, float gpa) {
		strcpy(this->fName, fName);
		strcpy(this->lName, lname);
		this->ID = ID;
		this->gpa = gpa;
	}
};

