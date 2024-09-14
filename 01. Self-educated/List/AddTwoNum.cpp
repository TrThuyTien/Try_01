#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node () : data(0), next(nullptr) {};
};

struct List {
    Node *head;
    Node *tail;
};

Node *createNode (const int& val) {
    Node *node = new Node;
    node->data = val;
    node->next = nullptr;
    return node;
}

void addTail (List& l, const int& val)

int main () {
    freopen ("AddTwoNum.inp", "r", stdin);
    freopen ("AddTwoNum.out", "w", stdout);
    // Create list l1
    List l1, l2;
    int val;
    do {
        cin >> val;
        if (val == -1) break;
        addTail(l1, val);
    } while (true);
}