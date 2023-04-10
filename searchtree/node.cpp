#include "node.h"
#include <iostream>
node :: node(int newdata) { //constructor
  left = NULL;
  right = NULL;
  data = newdata;
}

node :: ~node() {//destructor
  left = NULL;
  right = NULL;
}

void node :: setLeft(node* newLeft) {//sets left
  left = newLeft;
}

void node :: setRight(node* newRight) {//sets right
  right = newRight;
}

node* node :: getLeft() {//gets left
  return left;
}

node* node :: getRight() {//gets right
  return right;
}

void node :: setData(int newdata) {//sets data
  data = newdata;
}

int node :: getData() {//gets data
  return data;
}