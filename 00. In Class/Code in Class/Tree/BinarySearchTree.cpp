#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Cau truc 1 node cua cay
struct T_NODE{
    int key;
    T_NODE* left;
    T_NODE* right;
    T_NODE() : key(0), left(nullptr), right(nullptr) {};
};

// Cau truc du lieu cua cay

typedef T_NODE* TREE;

T_NODE* CreateT_Node (const int& data) {
    T_NODE* tNode = new T_NODE;
    if (tNode == nullptr) exit(1);
    tNode->key = data;
    tNode->left = nullptr;
    tNode->right = nullptr;
    return tNode;
}

void CreateTree (TREE& T) {
    T = nullptr;
}

int Insert(TREE& T, int x) {
    if (T != nullptr) {
        if (T->key == x) return 0;
        if (T->key > x) return Insert(T->left, x);
        return Insert(T->right, x);
    } 
    T = CreateT_Node(x);
    return 1;
}



void Input(TREE& T) {
    int x;
    do {
        cin >> x;
        if (x == -1) break;
        // Them gia tri vao cay
        Insert(T, x);
    } while (true);
}

void PreOrder (TREE Root) {
    // Su dung de quy
    if (Root != nullptr) {
        cout << Root->key << " ";
        PreOrder(Root->left);
        PreOrder(Root->right);
    }
    // Su dung stack

}

void InOrder (TREE Root) {
    // Su dung de quy
    // if (Root != nullptr) {
    //     InOrder(Root->left);
    //     cout << Root->key << " ";
    //     InOrder(Root->right);
    // }

    // Su dung stack
    stack <T_NODE*> st;
    st.push(Root);
    while (!st.empty()) {
        if (st.top()->left != nullptr) {
            T_NODE* temp = st.top()->left;
            st.top()->left = nullptr;
            st.push(temp);
        } else {
            cout << st.top()->key << " ";
            T_NODE* temp = st.top()->right;
            st.pop();
            if (temp != nullptr) {
                st.push(temp);
            }
        }
    }
}

void PostOrder (TREE Root) {
    if (Root != nullptr) {
        PostOrder(Root->left);
        PostOrder(Root->right);
        cout << Root->key << " ";
    }
}

void Output(TREE T) {
    InOrder (T);
}

int main () {
    freopen ("BinarySearchTree.inp", "r", stdin);
    freopen ("BinarySearchTree.out", "w", stdout);
    TREE T;
    // Tao cay rong
    CreateTree(T);
    // Nhap cay
    Input(T);
    // Xuat cay
    Output(T);
}