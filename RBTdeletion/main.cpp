#include <iostream>
#include "node.h"
#include <fstream>
#include <cstring>
#include <stdlib.h>
using namespace std;

//Created by Sahil Pai - 4/25/23
//Deletion on 5/19/23
//This project is a red black tree that allows for insertion of numbers. Got some help from Uno too.
//Sources: https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/
//https://github.com/Bibeknam/algorithmtutorprograms/blob/master/data-structures/red-black-trees/RedBlackTree.cpp
//https://math.oxford.emory.edu/site/cs171/redBlackTreeSearchingAndInserting/


//function prototypes
void print(node*, int);
void add(node**, node*, int);
void read(node**);
void leftro(node**, node*);
void rightro(node**, node*);
void redo(node**, node*);
node* search(node*, int);
void del(node**, int);
node* pred(node*);
node* fSib(node*);
void delcase1(node**, node*);
void delcase2(node**, node*);
void delcase3(node**, node*);
void delcase4(node**, node*);
void delcase5(node**, node*);
void delcase6(node**, node*);

int main() {
    node* root = new node(); //create the root for the tree
    bool s = true;
    while (s == true) {
        cout << "Choose from these options: add, print, read, search, delete, or quit" << endl;
        char input[80];
        cin >> input;
        if (strcmp(input, "add") == 0) {
            cout << "Enter the number you want to add: " << endl;
            int in;
            cin >> in;
            add(&root, root, in);
        }
        else if (strcmp(input, "quit") == 0) {
            s = false;
        }
        else if (strcmp(input, "print") == 0) {
            print(root, 0);
        }
        else if (strcmp(input, "read") == 0) { //file must be separated by commas
            read(&root);
        }
        else if (strcmp(input, "search") == 0) {
            int in;
            cout << "Enter the number you want to search for: " << endl;
            cin.ignore();
            cin >> in;
            search(root, in);//searches the tree for the number
        }
        else if (strcmp(input, "delete") == 0) {
            cout << "Enter the number you want to delete: " << endl;
            int in;
            cin >> in; 
            del(&root, in);
        }
    }
}

void read(node** root) { //read file
    cout << "Please input a filename" << endl;
    char filename[80];
    cin.ignore();
    cin.getline(filename, 80);
    ifstream newFile; 
    newFile.open(filename);
        while (newFile.eof() != true) {
            char* s = new char[4]; 
            newFile.getline(s, 5, ','); //used to split the comma
            int in = atoi(s); //need to convert to int
            add(&(*root), (*root), in); //call the add function
        }
    newFile.close();
}

void print(node* parent, int count) {
    if (parent->getRight() != NULL) {
        print(parent->getRight(), count + 1); 
    }
    int temp = count;
    while (count > 0) { //to format the tree properly
        cout << "   "; 
        count--;
    }
    if (parent->getCol() == 0) {
        //colorize text: https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c
        cout << "\033[31m" << parent->getData() << "\033[0m" << endl;
        //cout << parent->getData() << endl;
    }
    else {
        cout << parent->getData() << endl;
    }
    if (parent->getLeft() != NULL) {
        print(parent->getLeft(), temp + 1);
    }
}

void add(node** root, node* parent, int toin) {
    if (parent->getData() == 0) {
        parent->setCol(1);
        parent->setData(toin); //makes data an actual input
    }
    else { //from binary tree
        if (toin < parent->getData()) { //if the input is less than the data of the parent
            if (parent->getLeft() == NULL) { //if the left side doesnt exist
                node* newnode = new node();
                newnode->setData(toin);
                newnode->setParent(parent);
                parent->setLeft(newnode);
                redo(root, newnode); //ensures that the red black tree doesn't violate the main properties of a red black tree
            }
            else {
                add(root, parent->getLeft(), toin); //left side
            }
        }
        else { // right or equal node
            if (parent->getRight() == NULL) {
                node* newnode = new node();
                newnode->setData(toin);
                newnode->setParent(parent);
                parent->setRight(newnode);
                redo(root, newnode);
            }
            else {
                add(root, parent->getRight(), toin); // right side
            }
        }
    }
}

void leftro(node** root, node* rotateN) {
    node* y = rotateN->getRight(); //makes sure that the rotated nodes are left
    rotateN->setRight(y->getLeft()); // shifts the left to the original on the right
    if (y->getLeft() != NULL) { //for a new parent
        y->getLeft()->setParent(rotateN);
    }
    y->setParent(rotateN->getParent());
    if (rotateN == (*root)) { 
        (*root) = y; 
    }
    else {
        if (rotateN == rotateN->getParent()->getLeft()) { //if it was the child of the left parent
            rotateN->getParent()->setLeft(y); 
        }
        else {
            rotateN->getParent()->setRight(y);
        }
    }
    y->setLeft(rotateN); //y left original node
    rotateN->setParent(y); //original node parent = y
}

void rightro(node** root, node* rotateN) {
    //same as left but on the right side
    //logic is the same but variables are swapped
    node* y = rotateN->getLeft(); 
    rotateN->setLeft(y->getRight());
    if (y->getRight() != NULL) {
        y->getRight()->setParent(rotateN);
    }
    y->setParent(rotateN->getParent()); 
    if (rotateN == (*root)) { 
        (*root) = y; 
    }
    else {
        if (rotateN == rotateN->getParent()->getLeft()) {
            rotateN->getParent()->setLeft(y); 
        }
        else {
            rotateN->getParent()->setRight(y); 
        }
    }
    y->setRight(rotateN);
    rotateN->setParent(y);
}

//https://www.programiz.com/dsa/red-black-tree
//Used this for the general logic of fixing a red black tree after insertion
void redo(node** root, node* z) {
    while (z->getParent() != NULL && z->getParent()->getCol() == 0 && z != (*root)) { //while the entry is not the root and the parent is red (terminate at case 2)
        if (z->getParent() == z->getParent()->getParent()->getLeft()) { //checks to see if the parent is left of the grandparent
            node* y = z->getParent()->getParent()->getRight(); 
            if (y != NULL && y->getCol() == 0) { //test case 3
                z->getParent()->setCol(1); // set parent to black
                y->setCol(1); //make uncle black
                z->getParent()->getParent()->setCol(0); //therefore grandparent is red 
                z = z->getParent()->getParent();
            }
            else {
                if (z == z->getParent()->getRight()) { //case 4
                    z = z->getParent(); 
                    leftro(root, z); //rotation
                }
                z->getParent()->setCol(1); //case 4
                z->getParent()->getParent()->setCol(0); //set grandparent to red
                rightro(root, z->getParent()->getParent()); //rotate
            }
        }
        else { //right of the grandparent
            node* y = z->getParent()->getParent()->getLeft(); 
            if (y != NULL && y->getCol() == 0) { //case 3
                z->getParent()->setCol(1); //set parent to black
                y->setCol(1); //newnode = black
                z->getParent()->getParent()->setCol(0); //grandparent to red
                z = z->getParent()->getParent();
            }
            else {
                if (z == z->getParent()->getLeft()) { //case 4
                    z = z->getParent(); 
                    rightro(root, z); 
                }
                z->getParent()->setCol(1); 
                z->getParent()->getParent()->setCol(0); //set grandparent to red
                leftro(root, z->getParent()->getParent()); // rotate
            }
        }
    }
    (*root)->setCol(1); //root case
}

node* search(node* check, int inTree) {
    while (check != NULL) {//checks the entire tree
        if (inTree == check->getData()) {//if the data matches the number
            cout << "The number " << inTree << " exists." << endl;
            return check;
        }
        else if (inTree < check->getData()) {
            check = check->getLeft();
        }
        else {
            check = check->getRight();
        }
    }
    cout << "The number " << inTree << " does not exist." << endl; //does not exist
    return NULL;
}

void del(node** root, int del) {
    node* deleting = search((*root), del); //checks to see what should be deleted

    if (deleting != NULL) { //get the predecessor
        node* tracker = deleting;
        if (deleting->getLeft() == NULL || deleting->getRight() == NULL)
            tracker = deleting;
        else
            tracker = pred(deleting);

        if (tracker != deleting)
            deleting->setData(tracker->getData());

        node* trackchild = tracker->getLeft() != NULL ? tracker->getLeft() : tracker->getRight(); //checks to see if the real child is taken

        //for the sentinel (starts as black)
        //https://www.cs.dartmouth.edu/~thc/cs10/lectures/0519/0519.html#:~:text=A%20red%2Dblack%20tree%20is,the%20sentinel%20is%20always%20black.
        if (trackchild == NULL) { 
            trackchild = new node();
            trackchild->setCol(1);
        }

        trackchild->setParent(tracker->getParent()); //updates the parent

        if (tracker->getParent() == NULL)
            (*root) = trackchild; //makes the child the root
        else if (tracker == tracker->getParent()->getLeft())
            tracker->getParent()->setLeft(trackchild); //left child becomes the tracker for child
        else
            tracker->getParent()->setRight(trackchild);

        if (tracker->getCol() == 1) { // checks if tracker is black
            if (trackchild->getCol() == 1) // checks if child is vlack
                delcase1(root, trackchild); //case 1
            else
                trackchild->setCol(1); //update to black
        }

        if (trackchild->getIsDel() && trackchild != (*root)) { //if the child is a sentinal
            if (trackchild == tracker->getParent()->getLeft()) //this updates the parent's children
                trackchild->getParent()->setLeft(NULL);
            else
                trackchild->getParent()->setRight(NULL);
            trackchild->setParent(NULL);
            delete trackchild;
        }

        delete tracker;
    }
}

node* fSib(node* checking) {
    node* sibling; // sibling of the checking node
    //checks the left first, and if the parent is left, then the sibling is right.
    //Else, sibling is the parent left
    sibling = (checking->getParent()->getLeft() == checking) ? checking->getParent()->getRight() : checking->getParent()->getLeft();
    return sibling;
}

node* pred(node* high) {
    while (high->getRight() != NULL) { //checks the right side
        high = high->getRight();
    }
    return high;
}


//Deletion cases RBT: https://medium.com/analytics-vidhya/deletion-in-red-black-rb-tree-92301e1474ea

void delcase1(node** root, node* checking) {
    if (checking->getParent() != NULL) {//checks to see if there is a root
        delcase2(root, checking); //next case
    }
}

void delcase2(node** root, node* checking) { //checks to see if the sibling is red
    node* sibling = fSib(checking);

    if (sibling->getCol() == 0) { //red = 0
        checking->getParent()->setCol(0);// therefore parent is red
        sibling->setCol(1); //make sibling black
        if (checking == checking->getParent()->getLeft()) {
            leftro(root, checking->getParent());
        }
        else {
            rightro(root, checking->getParent());
        }
    }
    delcase3(root, checking); //next test case
}

void delcase3(node** root, node* checking) { //if parent, sibling, and child of sibling = black
    node* sibling = fSib(checking);
    node* parent = checking->getParent();

    if (parent->getCol() && sibling->getCol() &&
        (!sibling->getLeft() || sibling->getLeft()->getCol()) &&
        (!sibling->getRight() || sibling->getRight()->getCol())) { //checks for the comment above

        sibling->setCol(0); //make sibling red
        delcase1(root, parent);
    }
    else {
        delcase4(root, checking); //next case
    }
}

void delcase4(node** root, node* checking) { //sibling + children = black; parent = red
    node* sibling = fSib(checking);
    node* parent = checking->getParent();

    if (!parent->getCol() && sibling->getCol()) {
        if ((!sibling->getLeft() || sibling->getLeft()->getCol()) &&
            (!sibling->getRight() || sibling->getRight()->getCol())) { //checks for the comment above
            sibling->setCol(0);
            parent->setCol(1);
        }
        else {
            delcase5(root, checking);
        }
    }
    else {
        delcase5(root, checking);
    }
}

void delcase5(node** root, node* checking) { 
    node* sibling = fSib(checking);

    if (sibling->getCol()) {
        node* parent = checking->getParent();
        if (checking == parent->getLeft() && //left of the parent and the right sibling is black
            (!sibling->getRight() || sibling->getRight()->getCol())) {
            sibling->setCol(0); //make sibling red
            if (sibling->getLeft())
                sibling->getLeft()->setCol(1);
            rightro(root, sibling);
        }
        else if (checking == parent->getRight() &&
            (!sibling->getLeft() || sibling->getLeft()->getCol())) {
            sibling->setCol(0);
            if (sibling->getRight())
                sibling->getRight()->setCol(1); //make red because of cases 2,3 and 4
            leftro(root, sibling);
        }
    }
    delcase6(root, checking);
}

void delcase6(node** root, node* checking) { //checks to see if sibling is black, and one child is red
    node* sibling = fSib(checking);
    node* parent = checking->getParent();

    sibling->setCol(parent->getCol());
    parent->setCol(1); //make parent black

    if (checking == parent->getLeft()) {
        if (sibling->getRight())
            sibling->getRight()->setCol(1); //right sibling is black
        leftro(root, parent);
    }
    else {
        if (sibling->getLeft())
            sibling->getLeft()->setCol(1); //left sibling is black
        rightro(root, parent);
    }
}

