/*
* TicTacToe game - allows 2 people to play a fun game
* Created by: Sahil Pai
* Help from Uno
*/

#include <iostream>
#include <cstring>
using namespace std;

struct Wins {
	int xWins = 0;
	int oWins = 0;
	int tie = 0;
};

// print the board
void setup(char arr[3][3]) {
	cout << "    |    |    \n";
	cout << "  " << arr[0][0] << " |  " << arr[0][1] << " |  " << arr[0][2] << "  \n";
	cout << "____|____|____\n";
	cout << "    |    |    \n";
	cout << "  " << arr[1][0] << " |  " << arr[1][1] << " |  " << arr[1][2] << "  \n";
	cout << "____|____|____\n";
	cout << "    |    |    \n";
	cout << "  " << arr[2][0] << " |  " << arr[2][1] << " |  " << arr[2][2] << "  \n";
	cout << "    |    |    \n";

}

 // check for a win or draw
bool checkForWin(char arr[3][3], bool change, Wins &person) {
	int counter = 0;
	for (int i = 0; i < 3; i++) {
	  if (((arr[i][0] == arr[i][1]) && (arr[i][0] == arr[i][2])) || ((arr[0][i] == arr[1][i]) && (arr[0][i] == arr[2][i]))
	      || ((arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2])) || ((arr[0][2] == arr[1][1]) && (arr[1][1] == arr[2][0]))) {
			if (!change) {
				person.xWins++;
				cout << "X wins" << endl;
			}
			else {
				person.oWins++;
				cout << "O wins" << endl;
			}
			return true;
		}
		for (int j = 0; j < 3; j++) {
			if (arr[i][j] == 'X' || arr[i][j] == 'O') {
				counter++;
			}
		}
	}
	if (counter == 9) {
		person.tie++;
		cout << "tie" << endl;
		return true;
	}
	return false;
}

// changes the turn and points. Infinitely plays the game
void turn(char arr[3][3]) {
	Wins person;
	int input;
	while (true) {
		bool change = true;
		while (!checkForWin(arr, change, person)) {
			cin >> input;
			if (input > 9) {
				cout << "Enter a value, 1-9" << endl;
				continue;
			}
			char& spot = reinterpret_cast<char*>(arr)[input - 1]; // access memory as 1d array.
			if (spot == 'X' || spot == 'O') {
				cout << "Illegal move!\n";
				continue;
			}
			spot = change ? 'X' : 'O';
			change = !change;
			setup(arr);
		}
		cout << "X wins: " << person.xWins << endl;
		cout << "O wins: " << person.oWins << endl;
		cout << "Ties: " << person.tie << endl;
		cout << "Starting new game..." << endl;
		for (int i = 0; i < 9; i++) {
			reinterpret_cast<char*>(arr)[i] = i + '1'; // access memory as 1d array.
		} 
		setup(arr);
	}
}

// MAIN
int main() {
	char arr[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
	cout << "Welcome to tic tac toe. Enter the number where you want to place your letter. \n";
	setup(arr);
	turn(arr);
	return 0;
}
