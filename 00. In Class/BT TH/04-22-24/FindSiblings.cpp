/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>

using namespace std;
struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};

typedef TNODE* TREE;

void CreateEmptyTree(TREE &T) {
	T = NULL;
}

TNODE* CreateTNode(int x) {
	TNODE *p=new TNODE; //cấp phát vùng nhớ động
	p->key = x; //gán trường dữ liệu của node = x
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
int Insert(TREE &T, TNODE *p) {
	if (T) {
		if (T->key == p->key) return 0;
		if (T->key > p->key)
			return Insert(T->pLeft, p);
		return Insert(T->pRight, p);
	}
	T = p;
	return 1;
}
void CreateTree(TREE &T){
	int x;
	do {
		cin >> x;
		if(x==-1) break;
		Insert(T, CreateTNode(x));
	}while(true);
}

TNODE* FindParent(TREE Root, const int &x) {
	if(Root==NULL) return NULL;
	if(Root->key==x) return NULL;

	TNODE *pre=NULL;
	TNODE *p = Root;
	while (p != NULL) {
		if (x == p->key) return pre;
		pre=p;
		if (x < p->key)	p = p->pLeft;
		else	p = p->pRight;
	}
	return NULL;
}

//###INSERT CODE HERE -
void FindSiblings(TREE T, const int& x) {
    if (T == NULL) {
        cout << "Empty Tree.";
        return;
    }
    TNODE* node = FindParent(T, x);
    if (x == T->key) cout << x << " is Root.";
    else if (node == NULL) cout << "Not found " << x << ".";
    else {
        if (x > node->key) {
            if (node->pLeft != NULL) cout << node->pLeft->key << " and " << x << " are siblings.";
            else cout << x << " has no siblings.";
        } else {
            if (node->pRight != NULL) cout << x << " and " << node->pRight->key << " are siblings.";
            else cout << x << " has no siblings.";
        }
    }
}

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int x;
	cin >> x;

	FindSiblings(T, x);

	return 0;
}

