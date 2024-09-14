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
TNODE* CreateTreeNode(int x) {
    TNODE* p = new TNODE;
    if (p == NULL) exit(1);
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

int Insert(TREE& T, int x) {
    if (T != NULL) {
        if (T->key == x) return 0;
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

void Replace(TNODE* &p, TREE& T) {
    if (T->pLeft != NULL) {
        Replace(p, T->pLeft);
    } else {
        p->key = T->key;
        p = T;
        T = T->pRight;
    }
}

void DeleteNode (TREE& T, int x) {
    if (T != NULL) {
        if (x < T->key) DeleteNode(T->pLeft, x);
        else if (x > T->key) DeleteNode(T->pRight, x);
        else {
            TNODE* p = T;
            if (T->pLeft == NULL) T = T->pRight;
            else {
                if (T->pRight == NULL) T = T->pLeft;
                else {
                    Replace(p, T->pRight);
                }
            }
            delete p;
        }
    }
}

void PreOder(TREE T) {
    if (T != NULL) {
        cout << T->key << " ";
        PreOder(T->pLeft);
        PreOder(T->pRight);
    }
}

void PrintTree(TREE T) {
    if (T == NULL) {
        cout << "Empty Tree.";
        return;
    } else PreOder(T);
}

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int x;
	cin >> x;

	DeleteNode(T, x);

	PrintTree(T);
	return 0;
}
