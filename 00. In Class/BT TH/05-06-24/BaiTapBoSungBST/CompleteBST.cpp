#include <iostream>
#include <queue>
#include <cmath>

#define N 1000

using namespace std;

struct TNODE {
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};

typedef TNODE* TREE;

TNODE *CreateTreeNode(int x)
{
    TNODE *p = new TNODE;
    if (p == NULL)
        exit(1);
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

int Insert(TREE &T, int x)
{
    if (T != NULL)
    {
        if (T->key == x)
            return 0;
        if (x < T->key)
            return Insert(T->pLeft, x);
        return Insert(T->pRight, x);
    }
    T = CreateTreeNode(x);
    return 1;
}

void CreateTree(TREE &T)
{
    int x;
    do {
        cin >> x;
        if (x == -1)
            break;
        Insert(T, x);
    } while (true);
}

bool IsCompleteBST (TREE T) {
    if (T == NULL) return false;
    queue<TNODE*> q;
    q.push(T);
    q.push(NULL);
    int height = 0;
    bool notChild = false; // t_node ko co con nao
    bool oneChild = false; // t_node co 1 con
    while (!q.empty()) {
        TNODE* node = q.front();
        q.pop();
        if (node != NULL) {
            if (node->pLeft != NULL) {
                // neu cac t_node truoc chi co 1 con hoac khong co con nao, ma t_node hien tai la co con ->false
                if (notChild || oneChild) return false;
                q.push(node->pLeft);
                if (node->pRight != nullptr) {
                    q.push(node->pRight);
                } else {
                    oneChild = true;
                }
            } else {
                // neu t_node khong co con trai ma co con phai -> false
                if (node->pRight != NULL) return false;
                else notChild = true;
            }
        } else {
            if (!q.empty()) q.push(NULL);
        }
    }
    return true;
}

int main () {
    TREE T;
    T = NULL;
    CreateTree(T);
    if (T == NULL) cout << "Empty Tree.";
    else cout << boolalpha << IsCompleteBST(T);
}