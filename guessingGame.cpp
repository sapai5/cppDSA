#include<iostream>
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

// This program creates a random number and compares it to your guess. It then evaluates how many guesses you had.

int main() {
  bool redo = true;
  // restart
  while (redo == true) {
  bool stillPlaying = true;
  int counter = 0;
  int randomNumber = 0;
  int yourNumber = 0;
  // below is the random number generator
  srand (time(NULL));
  randomNumber = rand() % 100;
  srand(time(0));
  while (stillPlaying == true) {
    // win conditions
    cout<<"Please enter your number: ";
    cin>>yourNumber;
    counter++;
    if (yourNumber == randomNumber) {
      cout<<"You won!" << endl;
      cout<<"Guesses: " << counter;
      stillPlaying = false;
    } else if (yourNumber <= randomNumber) {
      cout<<"Your guess is too low! ";
      stillPlaying == true;
    } else {
      cout<<"Your guess is too high. ";
      stillPlaying == true;
    }
  }
  // restart conditions
  cout<<"Play again? Y to play again or N to end game."<<endl;
  string input;
  cin>>input;
  if (input == "Y") {
    redo == true;
    } else {
    redo == false;
    break;
      }
  }
}