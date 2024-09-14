#include <iostream>

using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;
    TNode () : data(0), left(nullptr), right(nullptr) {};
};

typedef TNode* Tree;

TNode* createNode (const int& val) {
    TNode *node = new TNode;
    node->data = val;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

TNode* insertTree (Tree& T, const int& val) {
    if (T == nullptr) {
        return createNode(val);
    }
    if (T->data > val) {
        T->left = insertTree(T->left, val);
    } else {
        T->right = insertTree(T->right, val);
    }
    return T;
}

void inOrder (Tree T) {
    if (T != nullptr) {
        inOrder(T->left);
        cout << T->data << " ";
        inOrder(T->right);
    }
}

void preOrder (Tree T) {
    if (T != nullptr) {
        cout << T->data << " ";
        preOrder(T->left);
        preOrder(T->right);
    }
}

void postOder (Tree T) {
    if (T != nullptr) {
        postOder(T->left);
        postOder(T->right);
        cout << T->data << " ";
    }
}


int main () {
    freopen ("BinarySearchTree.inp", "r", stdin);
    freopen ("BinarySearchTree.out", "w", stdout);
    int val;
    Tree T = nullptr;
    do {
        cin >> val;
        if (val == -1) break;
        T = insertTree(T, val);
    } while (true);
    inOrder(T);
}