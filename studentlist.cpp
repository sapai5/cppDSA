#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;

/* Written by: Sahil Pai
This project is a list that adds students. deletes students, and prints them.
Date: 11/3/2022
*/


// struct to act like global variables
struct student {
  char firstName[20];
  char lastName[20];
  int ID = 0;
  float GPA = 0;
};

//add students
void add(vector<student*> &v) {
  cout<<"add your students: "<<endl;
  student* s = new student();
  cout<<"Enter student first name: "<<endl;
  cout<<"First name: "; 
  cin>> s->firstName;
  cout<<"Enter student last name: "<<endl;
  cout<<"Last name: ";
  cin>> s->lastName;
  cout<<"Enter student ID: "<<endl;
  cout<<"ID: ";
  cin>> s->ID;
  cout<<"Enter student GPA: "<<endl;
  cout<<"GPA: ";
  cin>> s->GPA;
  cin.ignore(10, '\n');
  v.push_back(s);
}

// prints students
void print(vector<student*> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout<<"First name: ";
    cout<< v[i]->firstName<<endl;
    cout<<"Last name: ";
    cout<< v[i]->lastName<<endl;
    cout<<"ID number: ";
    cout<< v[i]->ID<<endl;
    cout<<"GPA: ";
    cout<< fixed << setprecision(2) << v[i] -> GPA <<endl;
    cout<< '\n' <<endl;
  }
}

// deletes students
void del(vector<student*> &v) {
  int enter;
  cout <<"Enter student id that you want removed: "<<endl;
  cin >> enter;
  for (int i = 0; i < v.size(); i++) {
    if (v[i]->ID== enter) {
      delete v[i];
      v.erase(v.begin() + i);
    }
  }
}

// interface to add, delete, print, quit
int main() {
  vector<student*> v;
  char input;
  bool cont = true;
  while (cont == true) {
    cout << "Enter 1 to add, 2 to delete, 3 to print, or 4 to quit." << endl;
    cin >> input;
    if (input == '1') {
      add(v);
    }
    else if (input == '2') {
      del(v);
    }
    else if (input == '3') {
      print(v);
    }
    else if (input == '4'){
      exit(0);
    } else {
      cont == true;
    }
  }
}
