/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <queue>
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

void CreateTree (TREE& T) {
    int x;
    do {
        cin >> x;
        if (x == -1) break;
        Insert(T, x);
    } while (true);
}

bool isEqual (TREE S, TREE T) {
    if (S == NULL && T == NULL) return true;
    if (S != NULL && T != NULL) {
        if (S->key != T->key) return false;
        return (isEqual(S->pLeft, T->pLeft) && isEqual(S->pRight, T->pRight)); 
    }
    return false;
}

bool isSubtree (TREE S, TREE T) {
    if (S == NULL) return true;
    if (T == NULL) return false;
    if (S->key == T->key) return isEqual(S, T);
    return (isSubtree(S, T->pLeft) || isSubtree(S, T->pRight));  
}

int main() {
	TNODE* S, *T;
	S=NULL; T=NULL;

	CreateTree(S);
	CreateTree(T);

	cout <<  boolalpha << isSubtree(S, T);

	return 0;
}
