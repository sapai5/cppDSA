#ifndef guard
#define guard
class node {
public:
	node();//constructor
	~node();//destructor
	//all function prototype
	void setLeft(node*);
	void setRight(node*);
	void setParent(node*);
	node* getLeft();
	node* getRight();
	node* getParent();
	void setData(int);
	int getData();
	void setCol(bool);
	bool getCol();
private:
	node* right;
	node* left;
	node* parent;
	int data;
	bool color;//red = 0, black = 1
};

#endif