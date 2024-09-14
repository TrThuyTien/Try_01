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
TNODE* CreateNode(int x) {
    TNODE* p = new TNODE;
    if (p == NULL) exit(1);
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
int Insert(TREE& T, int x) {
    if (T != NULL) {
        if (x == T->key) return 0;
        if (x > T->key) return Insert(T->pRight, x);
        else return Insert(T->pLeft, x);
    }
    T = CreateNode(x);
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

TNODE* FindNode (TREE T, int x) {
    if (T == NULL) return NULL;
    if (T->key == x) return T;
    else if (T->key > x) return FindNode(T->pLeft, x);
    return FindNode(T->pRight, x);
}

int Height(TREE T) {
    if (T == NULL) return -1;
    return 1 + max(Height(T->pLeft), Height(T->pRight));
}

int HeightOfNode(TREE T, int x) {
    T = FindNode(T, x);
    if (T == NULL) return -1;
    return Height(T);  
}

int main() {
	TREE T;
	int x;

	cin >> x;

	T = NULL;
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else cout << HeightOfNode(T, x);

	return 0;
}
