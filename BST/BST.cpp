#include "nodeT.h"

class BST
{
public:
	BST();
	~BST();
	void add(int data);
	bool search(int data);
	bool empty();

private:
	nodeT *root;
	int howManyChildren(nodeT *r);
};

BST::BST(){
	root=NULL;
}
bool BST::empty(){
	return root == NULL;
}

int BST::howManyChildren(nodeT * r){
	int iCont=0;
	if(r->getLeft() != NULL){
		iCont++;
	}
	if(r->getRight() != NULL){
		iCont++;
	}
	return iCont;
}
bool BST::search(int data){
	nodeT *aux = root;
	while(aux!=NULL){
		if (aux->getData() ==data){
			return true;
		}
		aux=(aux->getData() > data ? aux->getLeft() : aux->getRight());
		}
	return false;
}

void BST::add(int data){
	if (root==NULL)
	{
		root = new nodeT(data);
	}
else{
		nodeT *aux = root;
		nodeT *father = NULL;
		while (aux != NULL){
			if (aux->getData() == data){
				return;
			}
			father = aux;
			aux  = (aux->getData() > data ? aux->getLeft() : aux->getRight());
		}
		 father->getData() > data ? father->setLeft(new nodeT(data)) : father->setRight(new nodeT(data));
	}
}