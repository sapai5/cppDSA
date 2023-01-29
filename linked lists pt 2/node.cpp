#include "node.h"
#include <cstring>

node::node(student* stud2) {
	stud = stud2; //I (Sahil) changed the code here since it was backwards and didn't work
	next = NULL;
}
node::~node() {
	next = NULL;
}

student* node::getStudent() { //
	return stud;
}

void node::setNext(node* newnext) {//sets the next pointer to the corresponding node pointer
	next = newnext;
}

node* node::getNext() { //gets the next node pointer
	return next;
}
