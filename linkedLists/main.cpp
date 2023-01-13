#include <iostream>
#include <cstring>
#include "node.h" //header file

using namespace std;

void print(Node* node) { //print all nodes
	while (node != nullptr) {
		Student* stu = node->getStudent();
		cout << stu->firstName << ' ' << stu->lastName << ' ' << stu->ID << ' ' << stu->GPA << '\n';
		node = node->getNext();
	}
	cout << endl;
}

int main()
{
	Node* list = new Node(new Student((char*)"First", (char*)"Student", 111111, 4));
	Node* node = list;
	srand(time(NULL));
	for (int i = 0; i < 9; i++) {
		//randomize the student numbers and gpa
		Node* newNode = new Node(new Student((char*)"Firstname", (char*)"Lastname", (rand() % 900001) + 100000, (float)(rand() % 401 + 101) / 100.f));
		node->setNext(newNode);
		node = newNode;
	}
	print(list);
	return 0;
}
