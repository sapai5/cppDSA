#include <iostream>
#include <cstring>
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

    //front office
    char* name1 = new char[50]; //char array of names sets the name
    strcpy(name1, "Front Office");
    rm1->setTitle(name1);
    char* desc1 = new char[80]; //char array of descriptions sets the description
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
    char* desc2 = new char[50]; //char array of descriptions sets the description
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
    char* desc3 = new char[90]; //char array of descriptions sets the description
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
    char* desc4 = new char[90]; //char array of descriptions sets the description
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
    char* desc5 = new char[90]; //char array of descriptions sets the description
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
    char* desc6 = new char[90]; //char array of descriptions sets the description
    strcpy(desc6, "That's a lot of wires...");
    rm6->setDescription(desc6);
    map<char*, room*>* map6 = new map<char*, room*>; //map vector
    char* dir6 = new char[50]; //char array for direction
    strcpy(dir6, "WEST");
    map6->insert(pair<char*, room*>(dir6, rm5));
    rm6->setMap(map6);
    rooms->push_back(rm6);

    //Courtyard-----------------------------------------------------------------------------------------------START WORKING HERE
    char* name6 = new char[50]; //char array of names sets the name
    strcpy(name6, "Power Room");
    rm6->setTitle(name6);
    char* desc6 = new char[90]; //char array of descriptions sets the description
    strcpy(desc6, "That's a lot of wires...");
    rm6->setDescription(desc6);
    map<char*, room*>* map6 = new map<char*, room*>; //map vector
    char* dir6 = new char[50]; //char array for direction
    strcpy(dir6, "WEST");
    map6->insert(pair<char*, room*>(dir6, rm5));
    rm6->setMap(map6);
    rooms->push_back(rm6);
}
