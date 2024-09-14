#include<iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node() : data(-1), next(nullptr) {};
};

struct List {
    Node *head, *tail;
    List() : head(nullptr), tail(nullptr) {};
};

Node* createNode (const int& x) {
    Node *node = new Node;
    node->data = x;
    node->next = nullptr;
    return node;
}

void addTailList (List &l, const int& x) {
    Node *node = createNode(x);
    if (l.head == nullptr) {
        l.head = node;
        l.tail = l.head;
    } else {
        l.tail->next = node;
        l.tail = node; 
    }
}

void printList(const List& l) {
    if (l.head == nullptr) cout << "Empty List.";
    Node *node = l.head;
    while (node != nullptr) {
        cout << node->data << ' ';
        node = node->next;
    }
}

void swapMiddleNode (List& l) {
    if (l.head == nullptr) {
        return;
    }
    Node *curNode = l.head;
    int listSize = 0;
    while (curNode != nullptr) {
        curNode = curNode->next;
        listSize++;
    }
    delete curNode;
    if (listSize < 1) {
        exit;
    } 
    int mid = listSize/2;
    if (listSize & 1) mid++;
    Node *midNode = l.head;
    int i = 1;
    while (i < mid && midNode != nullptr) {
        i++;
        midNode = midNode->next;
    }
    int temp = midNode->data;
    midNode->data = l.tail->data;
    l.tail->data = temp;
}

int main () {
    freopen ("MakeMiddleNodeTail.inp", "r", stdin);
    freopen ("MakeMiddleNodeTail.out", "w", stdout);
    int val;
    List l;
    do {
        cin >> val;
        if (val == -1) break;
        addTailList(l, val);
    } while (true);
    
    swapMiddleNode(l);
    printList(l);
}