#include <iostream>
#include "node.h"
#include <fstream>
#include <cstring>
#include <stdlib.h>
using namespace std;

void add(node*);
node* create(int*, int);
void reccreate(node*, int*, int);
void insert(node*, node*);
void print(node*, int);
void deletenode(node*, int);

int main() {
  cout << "Welcome to Binary tree creater" << endl;
  //input code adapted from heap
  char c [80];
  bool b = true;
  int treear [100]; //array to initially hold values for tree
  while ( b == true) {//runs the input until valid
    cout << "Please input a input method (series or filename)" << endl;
    cin >> c;//takes method
    for(int i = 0; i < 100; i++) {//sets everything in array to val 0 (was issue at home computer)
      treear[i] = 0;
    }
    if (strcmp(c, "series") == 0) {//If the input is series
      b = false;//Proper input
      bool stillIn = true;//While still adding
      int count = 0;//spot to put new number
      cin.ignore(); //ignores previous cin in
      while(stillIn == true) {
	cout << "Please input a number to be in your heap, or END to construct your heap" << endl;
	char input [1000];//can hold number for input
	cin.getline(input,1000);//gets input
	if(strcmp(input, "END") == 0) { //Once end is typed, quits
	  stillIn = false;
	}
	else{
	  treear[count] = atoi(input); //take input, convert to int and add to array
	  count++;//increment spot to put int
	}
      }
    }
    else if (strcmp(c, "filename") == 0) {//if file
      cout << "Please input the list in the given input method" << endl;
      char filename[80];//for name of file
      cin.ignore();//ignores past cin
      cin.getline(filename, 80);//takes in the name
      ifstream newFile; //new file
      newFile.open(filename);//opens file with the name put in
      if (newFile == NULL) {//if file doesn't exist
	cout << "There was an error reading the file" << endl;
      }
      else {
	b = false;//input method correct
	int i = 0; //keeps track of spots in heap
	while (newFile.eof() != true) {//while not end of file
	  newFile >> treear[i];//puts each number seperated by whitespace in
	  i++;
	}
      }
      newFile.close();//closes file
    }
  }
  int length;
  for (int i = 0; i < sizeof(treear)/sizeof(treear[0]); i++) {//calculates elements in int array, puts in length
    if (treear[i] == 0) {
      length = i;
      break;
    }
  }
  
  node* root = create(treear, length); //creates tree of array
  print(root, 0);//prints the tree
  bool s = true;
  while(s == true) {//repeats till quit is typed
    cout << "Please choose to either insert, delete, print or quit" << endl;
    char input [80];
    cin >> input;
    if (strcmp(input, "insert") == 0) {
      add(root);//runs insert
    }
    else if (strcmp(input, "quit") == 0) {
      s = false;//exits loop and program
    }
    else if (strcmp(input, "delete") == 0) {
	cout << "What number do you wish to delete?" << endl;
	cin.ignore();
	int delnum;
	cin >> delnum;//takes in val to delete
	deletenode(root, delnum);// deletes the number
	print(root, 0);//prints tree
    }
    else if (strcmp(input, "print") == 0) {
      print(root, 0);//prints the tree
    }
  }
}


void add (node* root) {
  cout << "What number do you wish to insert?" << endl;
  cin.ignore();
  int insertnum;
  cin >> insertnum;//takes in val to insert
  node* newnode = new node(insertnum);//makes node with data value
  insert(root, newnode);//runs recursive function
  print(root, 0);//prints new tree
  
}

void insert(node* comp, node* toin) { //recursive funtion
  if(toin -> getData() < comp -> getData()) {//if less than data of comp
    if (comp -> getLeft() == NULL) {//if left doesn't exists
      comp -> setLeft(toin);//inserts on left
    }
    else {
      insert(comp -> getLeft(), toin);//runs with node to the left
    }

  }
  else { //if right or equal
    if (comp -> getRight() == NULL) { //if right doesn't exist
      comp -> setRight(toin);//inserted to right
    }
    else{
      insert(comp -> getRight(), toin);//runs with one to the right
    }
  }
}

node* create(int* treear, int length){ 
  node* root = new node(treear[0]);//makes root node holding first data val
  for (int i = 1; i < length; i++) {
    reccreate(root, treear, i);//runs reccreate for every array element
  }
  return root;//returns root of tree
}

void reccreate(node* comp, int* treear, int i) {
  node* newp = new node(treear[i]);//new node for new data
  if(treear[i] < comp -> getData()) {//if data is less than the preexisting node
    if (comp -> getLeft() == NULL) {//if no left
      comp -> setLeft(newp);//adds to left
    }
    else {
      reccreate(comp -> getLeft(), treear, i);//runs with one node to the left
    }
    
  }
  else {//if right
    if (comp -> getRight() == NULL) { // if right DNE
      comp -> setRight(newp);//adds to right
    }
    else{
      reccreate(comp -> getRight(), treear, i);//runs with one to the right
    }
  }
}

void print(node* parent, int count) {
  if(parent -> getRight() != NULL) {//if there is right
    print(parent -> getRight(), count + 1); //runs for one to right
  }
  int temp = count;//holds count for left side
  while (count > 0) {
    cout << "   "; //prints tabs for each level of tree
    count --;
  }
  cout << parent -> getData() << endl;//prints the node data
  if (parent -> getLeft() != NULL) {//if left exists
    print(parent -> getLeft(), temp + 1);//runs for one to the left
  }
}

void deletenode(node* comp, int del) {
  if(del < comp -> getData()) {//if data is less than node
    if (comp -> getLeft() != NULL) {//if the node has a left
      if (comp -> getLeft() -> getData() == del) {//if the next to the left equals the data
	//if the node to the left has no left node or right node
	if (comp -> getLeft() -> getLeft() == NULL && comp -> getLeft() -> getRight() == NULL){
	  delete comp -> getLeft();//deletes one to left with no other shift to tree
	  comp -> setLeft(NULL);//comp has left as null to avoid null pointer
	  return;
	}
      }
      deletenode(comp -> getLeft(), del);//Runs delete with one to the left
    }
    else{
      cout << "The number you wish to delete does not exist" << endl;
      return;
    }
  }
  else if(del > comp -> getData()) {//If data is greater than node
    if (comp -> getRight() != NULL) {// if there is a right
      if (comp -> getRight() -> getData() == del) {//if right equals delete
	//if right has no left or right
	if (comp -> getRight() -> getLeft() == NULL && comp -> getRight() -> getRight() == NULL){
	  delete comp -> getRight(); //deletes right
	  comp -> setRight(NULL);//sets right pointer to null
	  return;
	}
      }
      deletenode(comp -> getRight(), del);
    }
    else{
      cout << "The number you wish to delete does not exist" << endl;
      return;
    }
  }
  else { //they are equal
    //defaults to moving left up
    if (comp -> getLeft() != NULL) {//If left exist
      node* temp = comp -> getLeft(); //holds left data
      comp -> setData(temp -> getData());//sets data to equal value of left
      comp -> setLeft(temp -> getLeft());//gets left of left
      if (comp -> getRight() == NULL) { //if comp has no right
	comp -> setRight(temp -> getRight());//right can equal right of the temp
      }
      else {
	node* curr = temp;
	while(curr -> getRight() != NULL) {//gets to end of the right side of left
	  curr = curr -> getRight();
	}
	curr -> setRight(comp -> getRight());//sets the last one on right to have the comps right as its right
	comp -> setRight(temp -> getRight());//sets comp right to be the temp rigt
      }
      delete temp;//deletes node
      return;
    }
    else if(comp-> getRight() != NULL){//if right exists
      node* temp = comp -> getRight();//holds right node
      comp -> setData(temp -> getData());//sets comp data to be the rights data
      comp -> setLeft(temp -> getLeft());//sets the comp left to be right's left
      comp -> setRight(temp -> getRight());//sets the comp right to be right's right
      //the extra treeshift scenario is unnecessary since comp must have no left to reach here
      delete temp;//deletes the node
      return;
    }
  }
}