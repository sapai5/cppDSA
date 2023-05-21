#ifndef guard
#define guard
class node {
public:
	node(); 
	~node();
	//prototypes
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
	void setIsDel(bool);
	bool getIsDel();
	void reset();

private:
	node* left;
	node* right;
	node* parent;
	int data;
	bool color;
	bool isDel; //for when the tree is empty
};

#endif