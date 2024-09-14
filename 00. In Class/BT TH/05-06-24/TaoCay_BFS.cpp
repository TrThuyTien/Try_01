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
    p->pLeft =NULL;
    p->pRight =NULL;
    return p;
}

int Insert(TREE& T, int x) {
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

void PrintLevel(TREE T, int level) {
    if (T == NULL) {
        cout << "Empty Tree.";
        return;
    }
    queue<pair<TNODE*, int>> q;
    q.push({T, 0}); // {node, level}
    bool check = false;
    while (!q.empty()) {
        TNODE* p = q.front().first;
        int id = q.front().second;
        q.pop();
        if (id == level) {
            cout << p->key << " ";
            check = true;
        }
        if (id < level) {
            if (p->pLeft != NULL) q.push({p->pLeft, id + 1});
            if (p->pRight != NULL) q.push({p->pRight, id + 1}); 
        }
    }
    if (!check) cout << "Khong ton tai level " << level << ".";
}

int main() {
	TNODE* T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	int level;
	cin >> level;
	CreateTree(T);
	PrintLevel(T, level);
	return 0;
}
