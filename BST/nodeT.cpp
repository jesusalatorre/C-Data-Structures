class nodeT
{
public:
	nodeT(int data);
	int getData();
	void setData(int data);
	nodeT* getLeft();
	void setLeft(node *left);
	nodeT* getRight();
	void setRight(nodeT *right);
	
private:
	int data;
	nodeT *left;
	nodeT *right;

};
nodeT::nodeT(int data){
this->data=data;
this->left=NULL;
this->right=NULL;
}
int nodeT::getData(){
	return this->data;
}
void nodeT::setData(int data){
	this->data=data;
}
nodeT* nodeT::getLeft(){
	return this->left;
}
void nodeT::setLeft(nodeT *left){
	this->left=left;
}
nodeT* nodeT::getRight(){
	return this->right;
}
void nodeT::setRight(nodeT *right){
	this->right = right;
}