#include "node.h"
#include <iostream>
node::node() { //constructor
	left = NULL;
	right = NULL;
	parent = NULL;
	color = 0; //red = 0, black = 1
	data = 0;
	isDel = true; //this is for when the tree is empty
}

node :: ~node() {//destructor
	left = NULL;
	right = NULL;
}

void node::setLeft(node* newLeft) { //initilaize left
	left = newLeft;
}

void node::setRight(node* newRight) { //initilaize right
	right = newRight;
}

void node::setParent(node* newParent) {
	parent = newParent;
}

node* node::getLeft() {
	return left;
}

node* node::getRight() {
	return right;
}

node* node::getParent() {
	return parent;
}

void node::setData(int newdata) {
	data = newdata;
}

int node::getData() {
	return data;
}

void node::setCol(bool newcol) {
	color = newcol;
}

bool node::getCol() {
	return color;
}

void node::setIsDel(bool newDel) { //updates del
	isDel = newDel;
}

bool node::getIsDel() { //returns del
	return isDel;
}

void node::reset() {
	left = NULL;
	right = NULL;
	parent = NULL;
	color = 0;
	data = 0;
	isDel = true;
}