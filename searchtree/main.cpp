
//Created by Sahil Pai
//Date: 4/9/23
//binary tree
//remove and print from stackoverflow

#include <iostream>
#include <cstring>
#include <fstream> 
#include "Node.h"

using namespace std;

void add(Node*& curr, int val);
void print(Node* curr, int space);
void search(Node* curr, int val);
void remove(Node*& curr, int val, Node*& p, Node*& head);

int main() {
    char input[80];
    int data;
    Node* head = nullptr;
    bool quit = false;

    cout << "Welcome to Binary Search Tree" << endl;
    cout << "Type: add, file, search, remove, print, or quit." << endl;

    while (!quit) {
        cin.get(input, 80);
        cin.get();

        if (strcmp(input, "add") == 0) {
            cout << "Enter the number you would like to add" << endl;
            cin >> data;
            cin.get();
            add(head, data);
        }

        else if (strcmp(input, "file") == 0) {
            cout << "Enter the file path" << endl;
            cin.get(input, 80);
            cin.get();
            ifstream file(input);
            while (file >> data) {
                add(head, data);
            }
            file.close();
        }

        else if (strcmp(input, "search") == 0) {
            cout << "Enter the number you would like to search for" << endl;
            cin >> data;
            cin.get();
            search(head, data);
        }

        else if (strcmp(input, "remove") == 0) {
            cout << "Enter the number you would like to remove" << endl;
            cin >> data;
            cin.get();
            if (head != nullptr) {
                remove(head, data, head, head);
            }
            else {
                cout << "The tree is empty there is nothing to delete" << endl;
            }
        }

        else if (strcmp(input, "print") == 0) {
            cout << endl;
            print(head, 0);
            cout << endl;
        }

        else if (strcmp(input, "quit") == 0) {
            quit = true;
        }

        else {
            cout << "invalid command" << endl;
        }
    }
}

void add(Node*& curr, int val) {
    if (curr == nullptr) {
        curr = new Node();
        curr->setNum(val);
        return;
    }

    if (curr->getNum() > val) {
        if (curr->getLeft() == nullptr) {
            Node* temp = new Node();
            temp->setNum(val);
            curr->setLeft(temp);
        }
        else {
            Node* temp = curr->getLeft();
            add(temp, val);
        }
    }

    if (curr->getNum() <= val) {
        if (curr->getRight() == nullptr) {
            Node* temp = new Node();
            temp->setNum(val);
            curr->setRight(temp);
        }
        else {
            Node* temp = curr->getRight();
            add(temp, val);
        }
    }
}

void print(Node* curr, int space) {
    if (curr == nullptr) {
        return;
    }
    space += 10;
    print(curr->getRight(), space);
    cout << endl;
    for (int i = 10; i < space; i++) {
        cout << " ";
    }
    cout << curr->getNum() << "\n";
    print(curr->getLeft(), space);
}

void search(Node* curr, int val) {
    if (curr == nullptr) {
        cout << "the tree is empty" << endl;
        return;
    }

    while (curr != nullptr) {
        if (curr->getNum() == val) {
            cout << "yes the number exists" << endl;
            return;
        }
        else if (curr->getNum() > val) {
            curr = curr->getLeft();
        }
        else {
            curr = curr->getRight();
        }
    }

    cout << "The number isn't on the tree" << endl;
}

void remove(Node*& curr, int val, Node*& p, Node*& head) {

    if (curr->getNum() == val) {

        if (curr->getLeft() != NULL && curr->getRight() != NULL) {
            Node* temp = curr->getLeft();
            Node* prev = curr;
            int counter = 0;
            int nval;
            while (temp->getRight() != NULL) {
                if (counter >= 1) {
                    temp = temp->getRight();
                    prev = prev->getRight();
                }
                else {
                    temp = temp->getRight();
                    prev = curr->getLeft();
                }
                counter++;
            }

            nval = temp->getNum();

            remove(temp, temp->getNum(), prev, head);
            Node* replace = new Node();
            replace->setNum(nval);
            replace->setRight(curr->getRight());
            replace->setLeft(curr->getLeft());

            if (p->getNum() > val) {
                p->setLeft(replace);
            }
            else {
                p->setRight(replace);
            }

            if (curr == head) {
                delete curr;
                curr = NULL;
                curr = replace;
                return;
            }

            delete curr;
            curr = NULL;
            return;
        }

        if (curr->getLeft() != NULL) {

            Node* temp = curr->getLeft();
            curr->setNum(temp->getNum());
            curr->setRight(temp->getRight());
            curr->setLeft(temp->getLeft());
            delete temp;
            return;
        }

        if (curr->getRight() != NULL) {

            Node* temp = curr->getRight();
            curr->setNum(temp->getNum());
            curr->setRight(temp->getRight());
            curr->setLeft(temp->getLeft());
            delete temp;
            return;
        }

        if (curr->getLeft() == NULL && curr->getRight() == NULL) {

            if (p->getNum() > curr->getNum()) {
                delete curr;
                curr = NULL;
                p->setLeft(curr);
            }
            else if (p->getNum() < curr->getNum()) {
                delete curr;
                curr = NULL;
                p->setRight(curr);
            }
            else {
                delete p;
                p = NULL;
            }
            return;
        }

    }

    if (curr->getNum() > val) {
        if (curr->getLeft() != NULL) {
            Node* temp = curr->getLeft();
            remove(temp, val, curr, head);
        }
        else {
            cout << "This value is not in the tree" << endl;
            return;
        }
    }

    if (curr->getNum() < val) {
        if (curr->getRight() != NULL) {
            Node* temp = curr->getRight();
            remove(temp, val, curr, head);
        }
        else {
            cout << "This value is not in the tree" << endl;
            return;
        }
    }

}

