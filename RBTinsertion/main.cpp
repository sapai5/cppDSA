#include <iostream>
#include "node.h"
#include <fstream>
#include <cstring>
#include <stdlib.h>
using namespace std;

//Created by Sahil Pai - 4/25/23
//This project is a red black tree that allows for insertion of numbers

void print(node*, int);
void add(node**, node*, int);
void read(node**);
void leftro(node**, node*);
void rightro(node**, node*);
void redo(node**, node*);

int main() {
    node* root = new node();
    bool s = true;
    while (s == true) {
        cout << "Please choose to either add, read, print or quit" << endl;
        char input[80];
        cin >> input;
        if (strcmp(input, "add") == 0) {
            cout << "What number do you want to add" << endl;
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
        else if (strcmp(input, "read") == 0) {
            read(&root);
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
            newFile.getline(s, 5, ',');
            int in = atoi(s); 
            add(&(*root), (*root), in); 
        }
    newFile.close();
}

void print(node* parent, int count) {
    if (parent->getRight() != NULL) {
        print(parent->getRight(), count + 1); 
    }
    int temp = count;
    while (count > 0) {
        cout << "   "; 
        count--;
    }
    if (parent->getCol() == 0) {
        cout << "\033[31m" << parent->getData() << "\033[0m" << endl; //colorize
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
        parent->setData(toin);
    }
    else {
        if (toin < parent->getData()) {
            if (parent->getLeft() == NULL) {
                node* newnode = new node();
                newnode->setData(toin);
                newnode->setParent(parent);
                parent->setLeft(newnode);
                redo(root, newnode);
            }
            else {
                add(root, parent->getLeft(), toin);
            }
        }
        else {
            if (parent->getRight() == NULL) {
                node* newnode = new node();
                newnode->setData(toin);
                newnode->setParent(parent);
                parent->setRight(newnode);
                redo(root, newnode);
            }
            else {
                add(root, parent->getRight(), toin);
            }
        }
    }
}

void leftro(node** root, node* rotateN) {
    node* y = rotateN->getRight(); 
    rotateN->setRight(y->getLeft());
    if (y->getLeft() != NULL) {
        y->getLeft()->setParent(rotateN);
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
    y->setLeft(rotateN);
    rotateN->setParent(y);
}

void rightro(node** root, node* rotateN) { //right rotate
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

void redo(node** root, node* z) { //fix the rbt
    while (z->getParent() != NULL && z->getParent()->getCol() == 0 && z != (*root)) {
        if (z->getParent() == z->getParent()->getParent()->getLeft()) {
            node* y = z->getParent()->getParent()->getRight(); 
            if (y != NULL && y->getCol() == 0) {
                z->getParent()->setCol(1); 
                y->setCol(1); 
                z->getParent()->getParent()->setCol(0); 
                z = z->getParent()->getParent();
            }
            else {
                if (z == z->getParent()->getRight()) {
                    z = z->getParent(); 
                    leftro(root, z); 
                }
                z->getParent()->setCol(1); 
                z->getParent()->getParent()->setCol(0);
                rightro(root, z->getParent()->getParent()); 
            }
        }
        else {
            node* y = z->getParent()->getParent()->getLeft(); 
            if (y != NULL && y->getCol() == 0) {
                z->getParent()->setCol(1); 
                y->setCol(1); 
                z->getParent()->getParent()->setCol(0);
                z = z->getParent()->getParent();
            }
            else {
                if (z == z->getParent()->getLeft()) {
                    z = z->getParent(); 
                    rightro(root, z); 
                }
                z->getParent()->setCol(1); 
                z->getParent()->getParent()->setCol(0); 
                leftro(root, z->getParent()->getParent()); 
            }
        }
    }
    (*root)->setCol(1);
}
