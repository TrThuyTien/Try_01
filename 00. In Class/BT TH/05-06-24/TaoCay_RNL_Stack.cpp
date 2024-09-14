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
#include <stack>

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

void PrintTree(TREE T) {
    if (T == NULL) {
        cout << "Empty Tree.";
        return;
    }
    stack <TNODE*> st;
    st.push(T);
    while (!st.empty()) {
        if (st.top()->pRight != NULL) {
            TNODE* p = st.top()->pRight;
            st.top()->pRight = NULL;
            st.push(p);
        } else {
            TNODE* p = st.top()->pLeft;
            cout << st.top()->key << " ";
            st.pop();
            if (p != NULL) {
                st.push(p);
            }
        }
    }
}

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	PrintTree(T);
	return 0;
}
