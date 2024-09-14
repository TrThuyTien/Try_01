#include<iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {};
};

struct List {
    Node *head;
    Node *tail;
    List () : head(nullptr), tail(nullptr) {};
};

Node* createNode (int val) {
    Node *node = new Node;
    node->data = val;
    node->next = nullptr;
    return node;
}

void addNodeTail (List& l, int val) {
    Node *node = createNode(val);
    if (l.head == nullptr) {
        l.head = node;
        l.tail = l.head;
    } else {
        l.tail->next = node;
        l.tail = node;
    }
}

void reverseMiddleNode (List& l) {
    Node *curNode = l.head;
    int sizeList = 0;
    while (curNode != nullptr) {
        sizeList++;
        curNode = curNode->next;
    }
    if (sizeList < 3) return;
    int mid = sizeList / 2;
    if (sizeList & 1) mid++;
    curNode = l.head;
    int i = 1;
    while (i < mid) {
        Node *temp = createNode(curNode->data);
        l.tail->next = temp;
        l.tail = temp;
        curNode = curNode->next;
        i++;
    }
    l.head = curNode;
}

void printList (const List& l) {
    if (l.head == nullptr) {
        cout << "Empty List.";
        return;
    }
    Node *curNode = l.head;
    while (curNode != nullptr) {
        cout << curNode->data << " ";
        curNode = curNode->next;
    }
}

int main () {
    freopen ("MakeMiddleNodeHead.inp", "r", stdin);
    freopen ("MakeMiddleNodeHead.out", "w", stdout);
    List l;
    int val;
    do {
        cin >> val;
        if (val == -1) break;
        addNodeTail(l, val);
    } while (true);
    reverseMiddleNode(l);
    printList(l);
}