#include "room.h"

class item {
public:
	void setName(char*);
	char* getName();
	void setLocation(room*);
	room* getLoc();

	char* name;
	room* location;
};
