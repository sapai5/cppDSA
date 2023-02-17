#include "htable.h"
#include <set>
#include <fstream>

using namespace std;

bool newHash(Hash& table) {
	char input1[100];
	char input2[100];
	int ID;
	float gpa;
	cout << "Enter your first name: " << endl;
	cin >> input1;
	cout << "Enter your last name: " << endl;
	cin >> input2;
	cout << "Enter your student ID: " << endl;
	cin >> ID;
	cout << "Enter your gpa: " << endl;
	cin >> gpa;

	return table.addToHash(new Student(input1, input2, ID, gpa));
}

bool delStudent(Hash& table) {
	cout << "Enter student ID to delete student: " << endl;
	int id;
	cin >> id;
	return table.erase(id);
}

void fileFunction(Hash& table) {
	int temp3 = 0;
	cout << "Enter amount of students you want to insert: " << endl;
	cin >> temp3;
	ifstream strF("firstnames.txt");
	ifstream strL("lastnames.txt");
	char firstnames[20][20];
	char lastnames[20][20];
	for (int i = 0; i < 20; i++) {
		strF >> firstnames[i];
		strL >> lastnames[i];
	}
	for (int i = 0; i < temp3; i++) {
		if (!table.addToHash(new Student(firstnames[rand() % 20], lastnames[rand() % 20], 99999 + rand() % 999999, 3.f + ((float)(rand() % 180) / 100.f)))) {
			i--;
		}
	}
	strF.close();
	strL.close();
}

int main() {
	Hash table;
	char input[40];
	while (true) {
		cout << "Enter command: ADD, PRINT, DELETE, GENERATE, QUIT: " << endl;
		cin >> input;
		if (strcmp(input, "ADD") == 0) {
			newHash(table);
		}
		else if (strcmp(input, "PRINT") == 0) {
			table.print();
		}
		else if (strcmp(input, "DELETE") == 0) {
			delStudent(table);
		}
		else if (strcmp(input, "GENERATE") == 0) {
			fileFunction(table);
		}
		else if (strcmp(input, "QUIT") == 0) {
			break;
		}
		else {
			cout << "Wasn't an option" << endl;
		}
	}
}