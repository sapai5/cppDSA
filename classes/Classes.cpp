#include <iostream>
#include <cstring>
#include <vector>
#include "games.h"
#include "movies.h"
#include "music.h"

using namespace std;

int main()
{
    vector<Media*> allMedia;
    char input[50];
    while (true) {
        cout << "Please enter: add, search, print, delete, or quit" << endl;
        cout << "Enter action: " << endl;
        cin >> input;
        cin.ignore();
        if (strcmp(input, "print") == 0) {
            cout << "There are " << allMedia.size() << " entries.\n";
            for (int i = 0; i < allMedia.size(); i++) {
                cout << "---------------------------" << endl;
                allMedia[i]->print();
            }
            cout << "---------------------------" << endl;
        }
        else if (strcmp(input, "quit") == 0) {
            break;
        }
        else if (strcmp(input, "add") == 0) {
            cout << "Enter media type: videogame, music, movie" << endl;
            cin >> input;
            cin.ignore();
            if (strcmp(input, "videogame") == 0) {
                allMedia.push_back(new Game());
            }
            else if (strcmp(input, "music") == 0) {
                allMedia.push_back(new Music());
            }
            else if (strcmp(input, "movie") == 0) {
                allMedia.push_back(new Movie());
            }
            else {
                cout << "Input isn't an option." << endl;
            }

        }
        else if (strcmp(input, "search") == 0) {
            cout << "Enter 'year' or 'title' for your search filter." << endl;
            cin >> input;
            cin.ignore();
            if (strcmp(input, "title") == 0) {
                cout << "Enter media title: " << endl;
                cin.getline(input, 80);
                bool exists = false;
                for (int i = 0; i < allMedia.size(); i++) {
                    if (strcmp(allMedia[i]->getTitle(), input) == 0) {
                        exists = true;
                        cout << "---------------------------" << endl;
                        allMedia[i]->print();
                    }
                }
                cout << "---------------------------" << endl;
                if (exists != true) {
                    cout << "Media doesn't exist." << endl;
                }

            }
            else if (strcmp(input, "year") == 0) {
                cout << "Enter the year for your media: " << endl;
                int year;
                cin >> year;
                cin.ignore();
                bool exists = false;
                for (int i = 0; i < allMedia.size(); i++) {
                    if (allMedia[i]->getYear() == year) {
                        exists = true;
                        cout << "---------------------------" << endl;
                        allMedia[i]->print();
                    }
                }
                cout << "---------------------------" << endl;
                if (exists != true) {
                    cout << "Media doesn't exist." << endl;
                }
            }
        }
        else if (strcmp(input, "delete") == 0) {
            cout << "Delete by 'title' or 'year'?" << endl;
            cin >> input;
            cin.ignore();
            if (strcmp(input, "title") == 0) {
                cout << "Enter your media title: " << endl;
                cin.getline(input, 80);
                bool exists = false;
                for (int i = 0; i < allMedia.size(); i++) {
                    if (strcmp(allMedia[i]->getTitle(), input) == 0) {
                        exists = true;
                        cout << "Are you sure you want to delete \"" << allMedia[i]->getTitle() << "\" (" << allMedia[i]->getYear() << ")? Enter 'yes' or 'no': ";
                        cin >> input;
                        cin.ignore();
                        if (strcmp(input, "yes") != 0) {
                            cout << "Item is being skipped." << endl;
                            continue;
                        }
                        delete allMedia[i];
                        allMedia.erase(allMedia.begin() + i);
                    }
                }
                if (exists != true) {
                    cout << "Media doesn't exist." << endl;
                }
            }
            else if (strcmp(input, "year") == 0) {
                cout << "Enter the year of the media: " << endl;
                int year;
                cin >> year;
                cin.ignore();
                bool exists = false;
                for (int i = 0; i < allMedia.size(); i++) {
                    if (allMedia[i]->getYear() == year) {
                        exists = true;
                        cout << "Are you sure you want to delete \"" << allMedia[i]->getTitle() << "\" (" << allMedia[i]->getYear() << ")? Enter 'yes' or 'no': ";
                        cin >> input;
                        cin.ignore();
                        if (strcmp(input, "yes") != 0) {
                            cout << "Item is being skipped." << endl;
                            continue;
                        }
                        delete allMedia[i];
                        allMedia.erase(allMedia.begin() + i);
                    }
                }
                if (exists != true) {
                    cout << "Media doesn't exist." << endl;
                }
            }
        }
	    else {
	         cout << "Command isn't applicable." << endl;
	    }
    }
    cout << "Program Ended." << endl;
}

