#ifndef guard
#define guard
class node {
public:
	node();//constructor
	~node();//destructor
	//all of the function prototype
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
	node* right; //right node
	node* left; // left node
	node* parent;
	int data; //data
	bool color;//red = 0, black = 1
};

#endif
