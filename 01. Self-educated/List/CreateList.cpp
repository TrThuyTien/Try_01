#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;
};

struct linkedList {
    Node *head;
    Node *tail;
};

Node* createNode(int init_data) {
    Node *newNode = new Node;
    newNode->data = init_data;
    newNode->next = NULL;
    return newNode;
}

void createList(linkedList &l) {
    l.head = NULL;
    l.tail = NULL;
}

void addHeadList(linkedList &l, Node *node) {
    if (l.head == NULL) {
        l.head = node;
        l.tail = node;
    } else {
        node->next = l.head;
        l.head = node;
    }
}

void addTailList(linkedList &l, Node *node) {
    if (l.tail == NULL) {
        l.head = node;
        l.tail = node;
    } else {
        l.tail->next = node;
        l.tail = node;
    }
}

void addAfterQ(linkedList &l, Node *p, Node *q) {
    if (l.head == NULL) return;
    if (q == NULL) return;
    p->next = q->next;
    q->next = p;
    if (q == l.tail) l.tail = p;
}

void printList(linkedList l) {
    Node *node = l.head;
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

Node* findNode(linkedList l, int x) {
    Node *node = l.head;
    while (node != NULL && node->data != x) {
        node = node->next;
    }
    return node;
}

int removeHeadList(linkedList &l, int &x) {
    if (l.head == NULL) return 0;
    Node *node = new Node;
    node = l.head;
    x = node->data;
    l.head = node->next;
    delete node;
    if (l.head == NULL) l.tail == NULL;
    return 1;
}

int removeAfterQ(linkedList &l, Node *q, int &x) {
    if (l.head == NULL) return 0;
    if (q->next == NULL) return 0;
    if (q == NULL) return 0;
    Node *node = new Node;
    node = q->next;
    x = node->data;
    q->next = node->next;
    if (node->next == NULL) l.tail = q;
    delete node;
    return 1;
}

int main () {
    freopen("CreateList.inp", "r", stdin);
    freopen("CreateList.out", "w", stdout);
    linkedList l;
    createList(l);
    int val;
    while (cin >> val) {
        Node *node = new Node;
        node = createNode(val);
        addTailList(l, node);
    }
    printList(l);
    return 0;
}