/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
static
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
TNODE* CreateNode (const int& val) {
    TNODE* node = new TNODE;
    node->key = val;
    node->pLeft = NULL;
    node->pRight = NULL;
    return node;
}

int Insert (TREE& T, TNODE* p) {
    if (T != NULL) {
        if (T->key == p->key) return 0;
        if (T->key > p->key) return Insert(T->pLeft, p);
        return Insert(T->pRight, p);
    }
    T = p;
    return 1;
}

void CreateTree(TREE& T) {
    int val;
    do {
        cin >> val;
        if (val == -1) break;
        Insert(T, CreateNode(val));
    } while (true);
}

void CountNode(TREE T, int& count) {
    if (T != NULL) {
        count++;
        CountNode(T->pLeft, count);
        CountNode(T->pRight, count);
    }
}

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int count=0;
	CountNode(T, count);
	cout << count;
	return 0;
}
