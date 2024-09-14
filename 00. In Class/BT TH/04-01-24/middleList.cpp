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
    List () : head(nullptr), tail(nullptr) {};
};

Node *createNode (const int& val) {
    Node *node = new Node;
    node->data = val;
    node->next = nullptr;
    return node;
}

void addTail (List& l, const int& val) {
    Node *node = createNode(val);
    if (l.head == nullptr) {
        l.head = node;
        l.tail = node;
    } else {
        l.tail->next = node;
        l.tail = node;
    }
}

void createList (List& l) {
    int val;
    do {
        cin >> val;
        if (val == -1) break;
        addTail(l, val);
    } while (true);
}

int sizeOfList (const List& l) {
    if (l.head == nullptr) return 0;
    int n = 0;
    Node *curr = l.head;
    while (curr != nullptr) {
        n++;
        curr = curr->next;
    }
    return n;
}

void findMiddle (const List& l) {
    int n = sizeOfList(l);
    if (n == 0) {
        cout << "Empty List.";
        return;
    }
    int mid = n / 2;
    if (n & 1) mid++;
    int i = 1;
    Node *curr = l.head;
    while (i < mid) {
        curr = curr->next;
        i++;
    }
    cout << curr->data;
}

int main () {
    List l;
    createList(l);
    findMiddle(l);
}