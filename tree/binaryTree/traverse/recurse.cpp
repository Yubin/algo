#include <iostream>

using namespace std;


class intTreeNode {

/*
	private:
	intTreeNode *left;
	intTreeNode *right;
	int value;	
*/

	public:
	intTreeNode *left;
	intTreeNode *right;
	int value;	
	intTreeNode(){
		std::cout<< "intTreeNode()" << "\n";
		left = NULL;
		right = NULL;
		value = 0;
	}
	intTreeNode(int v){
		std::cout<< "intTreeNode("<< v <<")" << "\n";
		left = NULL;
		right = NULL;
		value = v;
        }
	~intTreeNode(){
		std::cout<< "destroy:"<< value << "\n";
		if (left != NULL)
			delete left;
		if (right != NULL)
			delete right;
	};

	void setLeft(intTreeNode *l){
		left = l;
	}

	void setRight(intTreeNode *r){
		right = r;
	}
	int visit () {
		std::cout<< value << ",";
		return 0;
	}
	int visit (intTreeNode* root) {
		std::cout<< root->value << ",";
		return 0;
	}
};

void inOrder(intTreeNode* root) {
	if (root != NULL) {
		root->visit();
		inOrder(root->left);
		inOrder(root->right);
	}	
}

void preOrder(intTreeNode* root) {
	if (root != NULL) {
		preOrder(root->left);
		root->visit();
		preOrder(root->right);
	}	
}

void postOrder(intTreeNode* root) {
	if (root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		root->visit();
	}	
}

int main () 
{
	intTreeNode *a = new intTreeNode(1);
	intTreeNode *b = new intTreeNode(2);
	intTreeNode *c = new intTreeNode(3);
	intTreeNode *d = new intTreeNode(4);
	intTreeNode *e = new intTreeNode(5);
	intTreeNode *f = new intTreeNode(6);
	intTreeNode *g = new intTreeNode(7);
	
	c->setLeft(f);
	c->setRight(g);
	b->setLeft(d);
	b->setRight(e);
	a->setLeft(b);
	a->setRight(c);
	std::cout<< "root:"<< a->value<<"\n";
	std::cout<< "left:"<< a->left->value<<"\n";
	std::cout<< "right:"<< a->right->value<<"\n";
	preOrder(a);
	std::cout<< "\n";
	inOrder(a);
	std::cout<<"\n";
	postOrder(a);
	std::cout<<"\n";
//	a = new intTreeNode(NULL,NULL,1);
//	a->visit ();
//	intTreeNode b(NULL,NULL,2);
//	b.visit();
	return 0;

}
