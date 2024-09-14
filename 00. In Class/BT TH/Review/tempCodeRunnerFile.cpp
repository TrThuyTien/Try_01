#include <iostream>

using namespace std;

struct TNode {
    int key;
    TNode *pLeft, *pRight;
};

typedef TNode* TREE;

TNode* CreateNode(int x) {
    TNode* p = new TNode;
    if (p == NULL) exit(1);
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

int Insert(TREE& T, int x) {
    if (T != NULL) {
        if (x == T->key) return 0;
        if (x < T->key) return Insert(T->pLeft, x);
        return Insert(T->pRight, x);
    }
    T = CreateNode(x);
    return 1;
}

void CreateTree(TREE& T) {
    T = NULL;
    int x;
    do {
        cin >> x;
        if (x == -1) break;
        Insert(T, x);
    } while(1);
}

void Replace(TREE& T, TNode* &p) {
    if (T->pLeft != NULL) Replace(T->pLeft, p);
    else {
        p->key = T->key;
        p = T;
        T = T->pRight;
    }
}

void DeleteNodeX(TREE& T, int x) {
    if (T == NULL) return;
    if (x < T->key) DeleteNodeX(T->pLeft, x);
    else if (x > T->key) DeleteNodeX(T->pRight, x);
    else {
        TNode *p;
        p = T;
        if (T->pLeft == NULL) T = T->pRight;
        else if (T->pRight == NULL) T = T->pLeft;
        else {
            Replace(T->pRight, p);
        }
        delete p;
    }
}

void PrintTree(TREE T) {
    if (T == NULL) return;
    cout << T->key << " ";
    PrintTree(T->pLeft);
    PrintTree(T->pRight);
}

int main () {
    freopen("DeleteNodeX.inp", "r", stdin);
    TREE T;
    CreateTree(T);
    int x;
    cin >> x;
    DeleteNodeX(T, x);
    if (T == NULL) cout << "Empty Tree\n";
    else PrintTree(T);
}