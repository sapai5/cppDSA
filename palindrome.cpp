#include<iostream>
#include<cstring>
using namespace std;

/*
 This program detects whether an input is a palindrome or not.
 Author: Sahil Pai
 Date: 9/25/22
*/

char *removeSpaces(char *palindrome)
{
  // remove spaces
    int i = 0, j = 0;
    while (palindrome[i])
    {
      if (isalnum(palindrome[i])) {
        palindrome[j++] = palindrome[i];
      }
      i++;
    }
    //convert to lowercase
    palindrome[j] = '\0';
    int count = 0;
    int len = strlen(palindrome);
    for (int x = 0; x < len; x++) {
      int c = palindrome[x];
      if (isalpha(c)) {
	count++;
        palindrome[x] = tolower(c);
      }
      }
    palindrome[count] = '\0';
    //cout<<palindrome<<endl;
    return 0;
}

   

int main () {
  char palindrome[80];
  char *pal2 = palindrome;
  cin.getline (palindrome,80,'\n');
  removeSpaces(pal2);
    
    int l = 0;
    int h = strlen(pal2)-1;
    
    // check if input is a palindrome
    while(h > l){
      if(pal2[l++] != pal2[h--]){
            cout << "Not a palindrome" << endl;
            return 0;
        }
    }
    cout << "Is a palindrome" << endl;
    return 0;
}
