#include <map>
#include <iostream>
#ifndef guard
#define guard

using namespace std;

class room {
public:
	void setDescription(char*);
	char* getDescription();
	void setMap(map<char*, room*>*);
	map<char*, room*>* getMap();
	void setTitle(char*);
	char* getTitle();

	char* description;
	map<char*, room*>* exits;
	char* title;
};

#endif//ends include_guard