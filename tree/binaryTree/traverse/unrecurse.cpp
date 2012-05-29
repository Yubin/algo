#include <iostream>
#include <stack>
#include <queue>

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

/**** a fast version of the inOrder traverse  *****/
/**** loop time: O(n)                         *****/
/**** condition time: O(2n)                   *****/
/**** total space: O(0.5n)                    *****/
void inOrder_fast(intTreeNode* root) {
	stack<intTreeNode*> s;
	int c = 0 ;
	while (root != NULL ){
		c++;
		root->visit();
		if (root->left!=NULL){
			if (root->right!=NULL){
				s.push(root->right);
			}
			root = root->left;
		}
		else{
			if (s.empty()){
				root = NULL;
			}else{	
				root = s.top();
				s.pop();
			}
		}
	}
	std::cout<<"Number:"<< c<<"\n";
}

/**** a nice version of the inOrder traverse  *****/
/**** but 2 times slower                      *****/
/**** time: O(2n)                             *****/
/**** condition time: O(2n)                   *****/
/**** space: O(n)                             *****/
void inOrder_nice(intTreeNode* root) {
        stack<intTreeNode*> s;
	int c = 0 ;
        while (root != NULL || !s.empty()){
		c++;
		if (root != NULL){
			root->visit();
			s.push(root);
			root = root->left;
		}
		else{
			root = s.top();
			s.pop();
			root = root->right;
		}
        }
	std::cout<<"Number:"<< c<<"\n";
}


/**** a nice version of the preOrder traverse  *****/
/**** time: O(1.5n)                              *****/
/**** condition time: O(2n)                    *****/
/**** space: O(0.5n)                              *****/
void preOrder_fast(intTreeNode* root) {
	stack <intTreeNode*> s;
	int c = 0;
	intTreeNode* visited = NULL;
	while (root != NULL) {
		c++;
		if ( root->left != visited && root->left !=NULL){
			s.push(root);
			root = root->left;
		}
		else{
			root->visit();
			if ( root->right != NULL){
				root = root->right;
			}
			else{
				if (s.empty()){
					root = NULL;
				}else{	
					root = s.top();
					s.pop();
					visited = root->left;
				}
			}
		}
	}
	std::cout<<"Number:"<< c<<"\n";
}

/**** a nice version of the preOrder traverse  *****/
/**** but  a little slower                     *****/
/**** time: O(2n)                              *****/
/**** condition time: O(2n)                    *****/
/**** space: O(n)                              *****/
void preOrder_nice(intTreeNode* root) {
	stack <intTreeNode*> s;
	while (root != NULL || !s.empty()) {
		if ( root!= NULL){
			s.push(root);
			root = root->left;
		}
		else{
			root = s.top();      // record the latest leftest node available
			root->visit();
			s.pop();
			root = root->right;  // past to it's right
		}
	}
}


void postOrder_nice(intTreeNode* root) {
	stack <intTreeNode*> s;
	intTreeNode* p = NULL;
	int c = 0;
	while (root != NULL || !s.empty()) {
		if ( root!= NULL){
			s.push(root);
			root = root->left;
		}
		else{
			root = s.top();
			if ( root->right !=NULL && root->right != p ){
				root = root->right;  // past to it's right
			}
			else{
				root->visit();
				p = root;
				s.pop();
				root = NULL;  // !!!
			}
		}
		c++;
	}
	std::cout<<"Number:"<< c<<"\n";
}


void widthOrder(intTreeNode* root){
	queue<intTreeNode*> pool ; 
	queue<int> level;
	pool.push(root);
    level.push(1);
	int currentLevel = 1;

	while (!pool.empty()){
		intTreeNode* tmp = pool.front();
		pool.pop();
		int tmpLevel = level.front();
		level.pop();

		// a new level coming
		if (currentLevel < tmpLevel ){
			cout << endl;
			currentLevel = tmpLevel;
		}
		cout<< tmp->value << " ";

		if ( tmp->left != NULL){
			pool.push(tmp->left);
			level.push(currentLevel+1);
		}
		
		if ( tmp->right!= NULL){
			pool.push(tmp->right);
			level.push(currentLevel+1);
		}
	}	
	cout << endl;
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
	intTreeNode *d1 = new intTreeNode(41);
	intTreeNode *d2 = new intTreeNode(42);
	intTreeNode *e1 = new intTreeNode(51);
	intTreeNode *e2 = new intTreeNode(52);
	intTreeNode *g1 = new intTreeNode(71);
	intTreeNode *g2 = new intTreeNode(72);
	
	g->setLeft(g1);
	g->setRight(g2);
	e->setLeft(e1);
	e->setRight(e2);
	d->setLeft(d1);
	d->setRight(d2);
	c->setLeft(f);
	c->setRight(g);
	b->setLeft(d);
	b->setRight(e);
	a->setLeft(b);
	a->setRight(c);
//	preOrder_nice(a);
//	preOrder_fast(a);
//	inOrder_nice(a);
//	inOrder_fast(a);
//	postOrder_nice(a);
	widthOrder(a);
//	a = new intTreeNode(NULL,NULL,1);
//	a->visit ();
//	intTreeNode b(NULL,NULL,2);
//	b.visit();
	return 0;

}
