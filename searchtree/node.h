#include <iostream>
#include <cstring>

using namespace std;

//start of header guard
#ifndef NODE_H
#define NODE_H

class Node {
public:
	Node(); //constructor
	Node* getLeft();
	Node* getRight(); //returns node pointer to right
	void setLeft(Node* l);
	void setRight(Node* r); //set pointer to right
	int getNum(); //returns number stored in node
	void setNum(int n);
private:
	Node* left; 
	Node* right; 
	int num; //value of number in node
};

#endif
