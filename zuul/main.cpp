#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>
#include <iomanip>
#include <map>
#include "room.h"
#include "item.h"

using namespace std;

int main()
{
    cout << "You are locked in an abandoned high school in a location you aren't familiar with. To survive, you need to escape the school. The exit doors are locked so you must find the key to get through the doors." << endl;
    vector <room*>* rooms = new vector<room*>();
    room* rm1 = new room(); //front office
    room* rm2 = new room(); //hallway
    room* rm3 = new room(); //biology
    room* rm4 = new room(); //engineering
    room* rm5 = new room(); //CS room
    room* rm6 = new room(); //power room
    room* rm7 = new room(); //courtyard
    room* rm8 = new room(); //math
    room* rm9 = new room(); //physics
    room* rm10 = new room(); //chemistry
    room* rm11 = new room(); //exit
    room* rm12 = new room(); //library
    room* rm13 = new room(); //counseling office
    room* rm14 = new room(); //cafeteria
    room* rm15 = new room(); //english
    room* i = new room();//inventory

    //front office
    char* name1 = new char[50]; //char array of names sets the name
    strcpy(name1, "Front Office");
    rm1->setTitle(name1);
    char* desc1 = new char[150]; //char array of descriptions sets the description
    strcpy(desc1, "You are in the front office. There are lots of filing cabinets around you.");
    rm1->setDescription(desc1);
    map<char*, room*>* map1 = new map<char*, room*>; //map vector
    char* dir1 = new char[50]; //char array for direction
    strcpy(dir1, "NORTH");
    map1->insert(pair<char*, room*>(dir1, rm2));
    rm1->setMap(map1);
    rooms->push_back(rm1);

    //Hallway
    char* name2 = new char[50]; //char array of names sets the name
    strcpy(name2, "Hallway");
    rm2->setTitle(name2);
    char* desc2 = new char[150]; //char array of descriptions sets the description
    strcpy(desc2, "You are in an abandoned hallway. Escape quick!");
    rm2->setDescription(desc2);
    map<char*, room*>* map2 = new map<char*, room*>; //map vector
    char* dir2 = new char[50]; //char array for direction
    strcpy(dir2, "NORTH");
    map2->insert(pair<char*, room*>(dir2, rm5));
    char* dir2_1 = new char[50]; //char array for direction
    strcpy(dir2_1, "EAST");
    map2->insert(pair<char*, room*>(dir2_1, rm3));
    char* dir2_2 = new char[50]; //char array for direction
    strcpy(dir2_2, "WEST");
    map2->insert(pair<char*, room*>(dir2_2, rm4));
    char* dir2_3 = new char[50]; //char array for direction
    strcpy(dir2_3, "SOUTH");
    map2->insert(pair<char*, room*>(dir2_3, rm1));
    rm2->setMap(map2);
    rooms->push_back(rm2);

    //Biology
    char* name3 = new char[50]; //char array of names sets the name
    strcpy(name3, "Biology");
    rm3->setTitle(name3);
    char* desc3 = new char[150]; //char array of descriptions sets the description
    strcpy(desc3, "WOW! Thats a lot of animals. Seems like a biology classroom...");
    rm3->setDescription(desc3);
    map<char*, room*>* map3 = new map<char*, room*>; //map vector
    char* dir3 = new char[50]; //char array for direction
    strcpy(dir3, "WEST");
    map3->insert(pair<char*, room*>(dir3, rm2));
    rm3->setMap(map3);
    rooms->push_back(rm3);

    //Engineering
    char* name4 = new char[50]; //char array of names sets the name
    strcpy(name4, "Engineering");
    rm4->setTitle(name4);
    char* desc4 = new char[150]; //char array of descriptions sets the description
    strcpy(desc4, "ROBOTS EVERYWHERE!!! Looks like an old engineering classroom...");
    rm4->setDescription(desc4);
    map<char*, room*>* map4 = new map<char*, room*>; //map vector
    char* dir4 = new char[50]; //char array for direction
    strcpy(dir4, "EAST");
    map4->insert(pair<char*, room*>(dir4, rm2));
    rm4->setMap(map4);
    rooms->push_back(rm4);

    //CS room
    char* name5 = new char[50]; //char array of names sets the name
    strcpy(name5, "Computer Science Room");
    rm5->setTitle(name5);
    char* desc5 = new char[150]; //char array of descriptions sets the description
    strcpy(desc5, "A computer lab...No one would notice if I played some games, right???");
    rm5->setDescription(desc5);
    map<char*, room*>* map5 = new map<char*, room*>; //map vector
    char* dir5 = new char[50]; //char array for direction
    strcpy(dir5, "EAST");
    map5->insert(pair<char*, room*>(dir5, rm6));
    char* dir5_1 = new char[50]; //char array for direction
    strcpy(dir5_1, "SOUTH");
    map5->insert(pair<char*, room*>(dir5_1, rm2));
    char* dir5_2 = new char[50]; //char array for direction
    strcpy(dir5_2, "EAST");
    map5->insert(pair<char*, room*>(dir5_2, rm7));
    rm5->setMap(map5);
    rooms->push_back(rm5);

    //Power Room
    char* name6 = new char[50]; //char array of names sets the name
    strcpy(name6, "Power Room");
    rm6->setTitle(name6);
    char* desc6 = new char[150]; //char array of descriptions sets the description
    strcpy(desc6, "That's a lot of wires...");
    rm6->setDescription(desc6);
    map<char*, room*>* map6 = new map<char*, room*>; //map vector
    char* dir6 = new char[50]; //char array for direction
    strcpy(dir6, "WEST");
    map6->insert(pair<char*, room*>(dir6, rm5));
    rm6->setMap(map6);
    rooms->push_back(rm6);

    //Courtyard
    char* name7 = new char[50]; //char array of names sets the name
    strcpy(name7, "Courtyard");
    rm7->setTitle(name7);
    char* desc7 = new char[150]; //char array of descriptions sets the description
    strcpy(desc7, "The only place where you can touch grass in the school...A courtyard, right!?");
    rm7->setDescription(desc7);
    map<char*, room*>* map7 = new map<char*, room*>; //map vector
    char* dir7 = new char[50]; //char array for direction
    strcpy(dir7, "SOUTH");
    map7->insert(pair<char*, room*>(dir7, rm5));
    char* dir7_1 = new char[50]; //char array for direction
    strcpy(dir7_1, "WEST");
    map7->insert(pair<char*, room*>(dir7_1, rm9));
    char* dir7_2 = new char[50]; //char array for direction
    strcpy(dir7_2, "EAST");
    map7->insert(pair<char*, room*>(dir7_2, rm8));
    char* dir7_3 = new char[50]; //char array for direction
    strcpy(dir7_3, "NORTH");
    map7->insert(pair<char*, room*>(dir7_3, rm14));
    rm7->setMap(map7);
    rooms->push_back(rm7);

    //Math
    char* name8 = new char[50]; //char array of names sets the name
    strcpy(name8, "Math");
    rm8->setTitle(name8);
    char* desc8 = new char[150]; //char array of descriptions sets the description
    strcpy(desc8, "Why is the quadratic equation on the board???");
    rm8->setDescription(desc8);
    map<char*, room*>* map8 = new map<char*, room*>; //map vector
    char* dir8 = new char[50]; //char array for direction
    strcpy(dir8, "NORTH");
    map8->insert(pair<char*, room*>(dir8, rm12));
    char* dir8_1 = new char[50]; //char array for direction
    strcpy(dir8_1, "EAST");
    map8->insert(pair<char*, room*>(dir8_1, rm7));
    char* dir8_2 = new char[50]; //char array for direction
    strcpy(dir8, "SOUTH");
    map8->insert(pair<char*, room*>(dir8_2, rm13));
    rm8->setMap(map8);
    rooms->push_back(rm8);

    //Physics
    char* name9 = new char[50]; //char array of names sets the name
    strcpy(name9, "Physics");
    rm9->setTitle(name9);
    char* desc9 = new char[150]; //char array of descriptions sets the description
    strcpy(desc9, "Is that an old Faraday cage in the corner? Now I know where to go if there is ever a lightning storm - a physics classroom!");
    rm9->setDescription(desc9);
    map<char*, room*>* map9 = new map<char*, room*>; //map vector
    char* dir9 = new char[50]; //char array for direction
    strcpy(dir9, "NORTH");
    map9->insert(pair<char*, room*>(dir9, rm10));
    char* dir9_1 = new char[50]; //char array for direction
    strcpy(dir9_1, "EAST");
    map9->insert(pair<char*, room*>(dir9_1, rm11));
    char* dir9_2 = new char[50]; //char array for direction
    strcpy(dir9, "WEST");
    map9->insert(pair<char*, room*>(dir9_2, rm7));
    rm9->setMap(map9);
    rooms->push_back(rm9);

    //Chemistry
    char* name10 = new char[50]; //char array of names sets the name
    strcpy(name10, "Chemistry");
    rm10->setTitle(name10);
    char* desc10 = new char[150]; //char array of descriptions sets the description
    strcpy(desc10, "Are those chemicals? Maybe a chemistry room...");
    rm10->setDescription(desc10);
    map<char*, room*>* map10 = new map<char*, room*>; //map vector
    char* dir10 = new char[50]; //char array for direction
    strcpy(dir10, "SOUTH");
    map10->insert(pair<char*, room*>(dir10, rm9));
    rm10->setMap(map10);
    rooms->push_back(rm10);

    //Exit
    char* name11 = new char[50]; //char array of names sets the name
    strcpy(name11, "Exit");
    rm11->setTitle(name11);
    char* desc11 = new char[150]; //char array of descriptions sets the description
    strcpy(desc11, "The exit room! Looks like there is a keyhole on the door...");
    rm11->setDescription(desc11);
    map<char*, room*>* map11 = new map<char*, room*>; //map vector
    char* dir11 = new char[50]; //char array for direction
    strcpy(dir11, "WEST");
    map11->insert(pair<char*, room*>(dir11, rm9));
    rm11->setMap(map11);
    rooms->push_back(rm11);

    //Library
    char* name12 = new char[50]; //char array of names sets the name
    strcpy(name12, "Library");
    rm12->setTitle(name12);
    char* desc12 = new char[150]; //char array of descriptions sets the description
    strcpy(desc12, "Wow, the amount of books here is astounding@");
    rm12->setDescription(desc12);
    map<char*, room*>* map12 = new map<char*, room*>; //map vector
    char* dir12 = new char[50]; //char array for direction
    strcpy(dir12, "SOUTH");
    map12->insert(pair<char*, room*>(dir12, rm8));
    rm12->setMap(map12);
    rooms->push_back(rm12);

    //Counseling Office
    char* name13 = new char[50]; //char array of names sets the name
    strcpy(name13, "Counseling Office");
    rm13->setTitle(name13);
    char* desc13 = new char[150]; //char array of descriptions sets the description
    strcpy(desc13, "Emotional support starts here...");
    rm13->setDescription(desc13);
    map<char*, room*>* map13 = new map<char*, room*>; //map vector
    char* dir13 = new char[50]; //char array for direction
    strcpy(dir13, "NORTH");
    map13->insert(pair<char*, room*>(dir13, rm8));
    rm13->setMap(map13);
    rooms->push_back(rm13);

    //Cafeteria
    char* name14 = new char[50]; //char array of names sets the name
    strcpy(name14, "Cafeteria");
    rm14->setTitle(name14);
    char* desc14 = new char[150]; //char array of descriptions sets the description
    strcpy(desc14, "That looks like a really nice place to eat lunch...");
    rm14->setDescription(desc14);
    map<char*, room*>* map14 = new map<char*, room*>; //map vector
    char* dir14 = new char[50]; //char array for direction
    strcpy(dir14, "SOUTH");
    map14->insert(pair<char*, room*>(dir14, rm7));
    char* dir14_1 = new char[50]; //char array for direction
    strcpy(dir14_1, "NORTH");
    map14->insert(pair<char*, room*>(dir14_1, rm15));
    rm14->setMap(map14);
    rooms->push_back(rm14);

    //English
    char* name15 = new char[50]; //char array of names sets the name
    strcpy(name15, "English");
    rm15->setTitle(name15);
    char* desc15 = new char[150]; //char array of descriptions sets the description
    strcpy(desc15, "This brings me back to the lit and comp days...");
    rm15->setDescription(desc15);
    map<char*, room*>* map15 = new map<char*, room*>; //map vector
    char* dir15 = new char[50]; //char array for direction
    strcpy(dir15, "SOUTH");
    map15->insert(pair<char*, room*>(dir15, rm14));
    rm15->setMap(map15);
    rooms->push_back(rm15);

    //create items
    vector <item*> items;
    item* i1 = new item();
    item* i2 = new item();
    item* i3 = new item();
    item* i4 = new item();
    item* i5 = new item();

    //Item: key
    char* itemName1 = new char[80];
    strcpy(itemName1, "Key");
    i1->setName(itemName1);
    i1->setLocation(rm6);
    items.push_back(i1);

    //Item: Robot
    char* itemName2 = new char[80];
    strcpy(itemName2, "Robot");
    i2->setName(itemName2);
    i2->setLocation(rm4);
    items.push_back(i2);

    //Item: Book
    char* itemName3 = new char[80];
    strcpy(itemName3, "Book");
    i3->setName(itemName3);
    i3->setLocation(rm3);
    items.push_back(i3);

    //Item: Hammer
    char* itemName4 = new char[80];
    strcpy(itemName4, "Hammer");
    i4->setName(itemName4);
    i4->setLocation(rm9);
    items.push_back(i4);

    //Item: Hydrogen Peroxide
    char* itemName5 = new char[80];
    strcpy(itemName5, "Hydrogen Peroxide");
    i5->setName(itemName5);
    i5->setLocation(rm10);
    items.push_back(i5);

    //Code for playing the game:
    bool stillPlaying = true;
    bool exitDoorOpen = false;
    room* current = rm1;
    while (stillPlaying == true) {
        cout << "You are in the " << current->getTitle() << " room." << endl;
        cout << current->getDescription() << endl;
        map<char*, room*>* currentMap = current->getMap();//get map for room
        cout << "Exits: " << endl;
        for (map<char*, room*>::iterator it = currentMap->begin(); it != currentMap->end(); ++it) {
            cout << it->first << endl; //Prints direction
        }
        bool legal = false;
        while (legal == false) {
            legal = false;
            cout << "Input a command (Input HELP to see all available commands)" << endl;
            char* command = new char[80];
            cin.getline(command, 80);//Gets the command
            if (strcmp(command, "NORTH") == 0 || strcmp(command, "SOUTH") == 0 || strcmp(command, "WEST") == 0 || strcmp(command, "EAST") == 0) {
                bool cont = true;

                if (strcmp(command, "EAST") == 0 && current == rm15) {
                    cout << "You need the key to enter this room." << endl;
                    cont = false;//Prevents room transition
                    legal = true;//legal move
                    if (i4->getLoc() == i) {
                        cout << "You got away with the robot. You can sell it and get rich. YOu win!" << endl;
                    }
                    else {
                        cout << "You escaped but got nothing out of it. At least you are alive." << endl;
                    }
                    stillPlaying = false;//stops game
                }
                if (cont == true) {
                    for (map<char*, room*>::iterator it = currentMap->begin(); it != currentMap->end(); ++it) {//go through map
                        if (strcmp(command, it->first) == 0) {
                            legal = true; //legal move
                            current = it->second; //changes room
                        }
                    }
                }
                for (vector<item*>::iterator it = items.begin(); it != items.end(); ++it) { //runs through all the items
                    if ((*it)->getLoc() == current) {
                        cout << "There is a " << (*it)->getName() << endl;
                    }
                }
                legal = true;//legal move
                if (strcmp(command, "Get") == 0) { //Will pickup item
                    for (vector<item*>::iterator it = items.begin(); it != items.end(); ++it) {
                        if ((*it)->getLoc() == current) {
                            cout << "Do you wish to pickup " << (*it)->getName() << "(answer Y or N)" << endl;
                            char yesno;
                            cin >> yesno;
                            cin.ignore();
                            if (yesno == 'Y') {
                                (*it)->setLocation(i);
                            }
                        }
                    }
                    legal = true; //legal move
                }
            }
            else if (strcmp(command, "Inventory") == 0) {//checks inventory
                cout << "You have: " << endl;
                for (vector<item*>::iterator it = items.begin(); it != items.end(); ++it) {
                    if ((*it)->getLoc() == i) {
                        cout << (*it)->getName() << endl;
                    }
                }
                legal = true;//legal move
            }

            else if (strcmp(command, "Drop") == 0) {
                cout << "You have: " << endl;
                for (vector<item*>::iterator it = items.begin(); it != items.end(); ++it) {
                    if ((*it)->getLoc() == i) {
                        cout << (*it)->getName() << endl;
                    }
                }
                cout << "Enter the Item you want to drop" << endl;
                char* itemDrop = new char[80];
                cin.getline(itemDrop, 80);
                bool drop = false;
                for (vector<item*>::iterator it = items.begin(); it != items.end(); ++it) {//runs through items
                    if ((*it)->getLoc() == i && strcmp((*it)->getName(), itemDrop) == 0) {
                        (*it)->setLocation(current);
                        cout << "Item has been dropped" << endl;
                        drop = true;
                    }
                }
                if (drop == false) {
                    cout << "Item is not in your inventory" << endl;
                }
                legal = true;
            }

            else if (strcmp(command, "Help") == 0) {
                cout << "Commands:" << endl;
                cout << "NORTH, SOUTH, EAST, or WEST" << endl;
                cout << "Help" << endl;
                cout << "Get" << endl;
                cout << "Drop" << endl;
                cout << "Quit" << endl;
                cout << "Inventory" << endl;
                legal = true;//legal move
            }

            else if (strcmp(command, "Quit") == 0) {
                legal = true; //legal move
                stillPlaying = false;
            }

            if (legal == false) { //if not legal move
                cout << "The inputted command is invalid" << endl;
            }
            


        }
    }
}
