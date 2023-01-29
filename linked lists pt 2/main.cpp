#include <iostream>
#include <cstring>
#include <iomanip>

#include "node.h"
#include "student.h"

/* created by: sahil pai
* 1/29/23
* student list using linked lists
*/


using namespace std;

bool newStudent(node*& list, node* before, node* same, node* ins) { //add the students to the list
    if (list == nullptr) {
        list = ins;
        return true;
    }
    if (same == nullptr) {
        before->setNext(ins);
        return true;
    }
    int IDcurrent = same->getStudent()->getID();
    int IDnew = ins->getStudent()->getID();
    if (IDcurrent > IDnew) {
        // This is the right spot
        if (before != nullptr) {
            before->setNext(ins);
        }
        else {
            list = ins;
        }
        ins->setNext(same);
        return true;
    }
    else if (IDcurrent == IDnew) {
        // There's already a student with the same ID so we can't insert 
        return false;
    }
    return newStudent(list, same, same->getNext(), ins);
}

bool addStudent(node*& list) { //takes user input
    char input[60];
    cout << "Enter the student first name." << endl;
    cin >> input;
    char input2[60];
    cout << "Enter the student last name." << endl;
    cin >> input2;
    int ID;
    cout << "Enter the student ID." << endl;
    cin >> ID;
    float input3;
    cout << "Enter the student GPA." << endl;
    cin >> input3;
    node* newNode = new node(new student(input, input2, ID, input3));
    return newStudent(list, nullptr, list, newNode);
}

void print(node* list) { //print the list
    if (list == nullptr) {
        return;
    }
    list->getStudent()->print();
    print(list->getNext());
}

bool newDelete(node*& list, node* before, node* same, int ID) {
    if (same == nullptr) {
        return false;
    }
    if (same->getStudent()->getID() == ID) {
        if (before != nullptr) {
            before->setNext(same->getNext());
        }
        else {
            list = same->getNext();
        }
        delete same;
        return true;
    }
    return newDelete(list, same, same->getNext(), ID);
}

bool deleteStudent(node*& list) {
    cout << "Enter the student ID you want to delete." << endl;
    int ID;
    cin >> ID;
    return newDelete(list, nullptr, list, ID);
}

float avg(node* same, float sum, int x) { //calculate avg
    if (same == nullptr) {
        return sum / x;
    }
    return avg(same->getNext(), sum + same->getStudent()->getGPA(), x + 1);
}

int main() {
    node* list = nullptr;
    bool stillPlaying = true;
    while (stillPlaying == true) {
        cout << "Enter 1 to add, 2 to print, 3 to delete, 4 for average, and 5 to quit." << endl;
        //char entry = new char[80];
        int enter = 0;
        cin >> enter;
        if (enter == 1) {
            addStudent(list);
        }
        else if (enter == 2) {
            print(list);
        }
        else if (enter == 3) {
            deleteStudent(list);
        }
        else if (enter == 4) {
            cout << "Average GPA: " << fixed << setprecision(2) << avg(list, NULL, NULL) << endl;
        }
        else if (enter == 5) {
            stillPlaying = false;
        }
        else {
            cout << "That wasn't an option." << endl;
            stillPlaying = true;
        }
    }
    cout << "Thanks for using this program." << endl;
    return 0;
}
