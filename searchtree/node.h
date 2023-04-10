#ifndef guard
#define guard
class node {
 public:
  node(int);//constructor
  ~node();//destructor
  //all function prototype
  void setLeft(node*);
  void setRight(node*);
  node* getLeft();
  node* getRight();
  void setData(int);
  int getData();
 private:
  node* left;//holds left node
  node* right;//holds right node
  int data;//holds data
};

#endif