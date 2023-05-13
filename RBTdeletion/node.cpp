#include "node.h"
#include <iostream>
node::node() { //constructor
	left = NULL;
	right = NULL;
	parent = NULL;
	color = 0;
	data = 0;
}

node :: ~node() {//destructor
	left = NULL;
	right = NULL;
}

void node::setLeft(node* newLeft) {
	left = newLeft;
}

void node::setRight(node* newRight) {
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

void node::setIsDel(bool newDel) {
	isDel = newDel;
}

bool node::getIsDel() {
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