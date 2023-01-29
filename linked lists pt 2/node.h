#pragma once
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "student.h"
using namespace std;

class node {
public:
	node(student* stud2);
	~node();
	student* getStudent();
	void setNext(node* newnext);
	node* getNext();
private:
	student* stud;
	node* next;
};

#endif
