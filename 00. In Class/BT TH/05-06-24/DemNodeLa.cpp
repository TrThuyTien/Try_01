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

//###INSERT CODE HERE -
TNODE* CreateTreeNode (int x) {
    TNODE* p = new TNODE;
    if (p == NULL) exit(1);
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

int Insert (TREE& T, int x) {
    if (T != NULL) {
        if (x == T->key) return 0;
        if (x < T->key) return Insert(T->pLeft, x);
        return Insert(T->pRight, x);
    } 
    T = CreateTreeNode(x);
    return 1;
}

void CreateTree(TREE& T) {
    int x;
    do {
        cin >> x;
        if (x == -1) break;
        Insert(T, x);
    } while (true);
}

void CountLeaf(TREE T, int& count) {
    if (T != NULL) {
        if (T->pLeft == NULL && T->pRight == NULL) count++;
        CountLeaf(T->pLeft, count);
        CountLeaf(T->pRight, count);
    }
}

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int count =0;
	CountLeaf(T, count);
	cout << count;
	return 0;
}
