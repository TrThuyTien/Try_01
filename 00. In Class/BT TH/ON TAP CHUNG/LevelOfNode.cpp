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
TNODE* CreateNode(int x) {
    TNODE* p = new TNODE;
    if (p == NULL) exit(1);
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

int Insert(TREE &T, int x) {
    if (T != NULL) {
        if (x == T->key) return 0;
        if (x < T->key) return Insert(T->pLeft, x);
        return Insert(T->pRight, x);
    }
    T = CreateNode(x);
    return 1;
}

void CreateTree(TREE &T) {
    int x;
    do {
        cin >> x;
        if (x == -1) break;
        Insert(T, x);
    } while(1);
}

bool FindNode(TREE T, int x) {
    if (T == NULL) return false;
    if (T->key == x) return true;
    if (x < T->key) return FindNode(T->pLeft, x);
    return FindNode(T->pRight, x);
}

int LevelOfNode(TREE T, int x) {
    if (T->key == x) return 0;
    if (x < T->key) return 1 + LevelOfNode(T->pLeft, x);
    return 1 + LevelOfNode(T->pRight, x);
}

void PrintLevel(TREE T, int x, int &level) {
    if (!FindNode(T, x)) {
        level = -1;
        return;
    }
    level = LevelOfNode(T, x);
}

int main() {
	TNODE* T;
	int x, level=-1;

	cin >> x;

	T = NULL;
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else {
		PrintLevel(T, x, level);
		cout << level;
	}
	return 0;
}

