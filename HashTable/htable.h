#pragma once

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stack>
#include "Student.h"

using namespace std;

struct Start {
	Student* student;
	Start* next;

	Start() {
		memset(this, 0x0, sizeof(Start));
	}

	Start(Student* stu) {
		this->student = stu;
		this->next = nullptr;
	}

	~Start() {
		delete student;
	}
};

//Hash Table

struct Hash { //https://www.digitalocean.com/community/tutorials/hash-table-in-c-plus-plus
	unsigned int s;
	Start** start;

	Hash() {
		this->s = 101;
		this->start = reinterpret_cast<Start**>(new unsigned long long[101]);
		memset(this->start, 0x0, 808);
	}


	unsigned int HashTableID(unsigned int id) {
		return id % s;
	}

	void print() { //print
		Student* array = new Student[s];
		int temp = 0;
		for (int i = 0; i < s; i++) {
			Start* st = start[i];
			while (st != nullptr) {
				array[temp++] = *st->student;
				st = st->next;
			}
		}
		sort(array, array + temp, [](Student& first, Student& second) { //got this from stack overflow
			return first.ID < second.ID;
			});
		for (int i = 0; i < temp; i++) {
			cout << "[" << array[i].ID << "] " << array[i].fName << " " << array[i].lName << " (" << fixed << setprecision(2) << array[i].gpa << ")\n";
		}
	}

	bool addToHash(Student* stu) {
		unsigned int hash = HashTableID(stu->ID);
		if (start[hash] == nullptr) {
			start[hash] = new Start(stu);
			return true;
		}
		Start* find = start[hash];
		Start* previous = nullptr;
		int temp2 = 0;
		while (find != nullptr) {
			previous = find;
			temp2++;
			if (find->student->ID == stu->ID) {
				delete stu;
				return false;
			}
			find = find->next;
		}
		previous->next = new Start(stu);
		if (temp2 > 3) {
			//Resize table (prev*2)
			cout << "Resizing table to " << (s * 2) << "!\n";
			stack<Student> students; //stack overflow
			for (int i = 0; i < s; i++) {
				while (start[i] != nullptr) {
					students.push(*start[i]->student);
					Start* y = start[i];
					start[i] = start[i]->next;
					delete y;
				}
			}
			s *= 2;
			this->start = reinterpret_cast<Start**>(new unsigned long long[s]);
			memset(this->start, 0x0, s * 8);
			while (!students.empty()) {
				addToHash(new Student(&students.top()));
				students.pop();
			}
		}
		return true;
	}

	bool erase(unsigned int ID) {
		unsigned int hash = HashTableID(ID);
		Start* find = start[hash];
		Start* previous = nullptr;
		if (find->student->ID == ID) {
			if (previous == nullptr) {
				start[hash] = find->next;
			}
			else {
				previous->next = find->next;
			}
			delete find;
			return true;
		}
		return false;
	}
};