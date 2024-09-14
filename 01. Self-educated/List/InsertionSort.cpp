#include<iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node () : data(0), next(nullptr) {};
};

struct List {
    Node *head;
    Node *tail;
    List () : head(nullptr), tail(nullptr) {};
};

Node* createNode (const int& val) {
    Node *node = new Node;
    node->data = val;
    node->next = nullptr;
    return node;
}

void addTail (List& l, const int& val) {
    Node *node = createNode(val);
    if (l.head == nullptr) {
        l.head = node;
        l.tail = l.head;
    } else {
        l.tail->next = node;
        l.tail = node;
    }
}

void Input (List& l, const int& n) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        addTail(l, val);
    }
}
void insert(List& l, Node *node) {
    
}
void InsertionSort (List &l) {
    Node *currNode = l.head->next;
    while (currNode != nullptr) {
        insert(l, currNode);
        currNode = currNode->next;
    }
}

int main () {
    freopen ("InsertionSort.inp", "r", stdin);
    freopen ("InsertionSort.out", "w", stdout);
    
}