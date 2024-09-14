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
    Node* node = createNode(val);
    if (l.head == nullptr) {
        l.head = node;
        l.tail = l.head;
    } else {
        l.tail->next = node;
        l.tail = node;
    }
}

void join2List (List& l1, const List& l2) {
    if (l1.head == nullptr) {
        l1 = l2;
    } else {
        l1.tail->next = l2.head;
        l1.tail = l2.tail;
    }
}

void replaceVal (List& l, const int& val1, const int& val2) {
    Node *node = l.head;
    while (node != nullptr) {
        if (node->data == val1) 
            node->data = val2;
        node = node->next;
    }
}

void print (const List& l) {
    if (l.head == nullptr) {
        cout << "Empty List.";
        return;
    }
    Node *node = l.head;
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
} 

int main () {
    freopen ("Join2List.inp", "r", stdin);
    freopen ("Join2List.out", "w", stdout);
    List l1, l2;
    int val;
    // scan l1
    do {
        cin >> val;
        if (val == -1) break;
        addTail(l1, val);
    } while (true);
    // print l1
    print(l1);
    cout << endl;

    // scan l2
    do {
        cin >> val;
        if (val == -1) break;
        addTail(l2, val);
    } while (true);
    // print l2
    print(l2);
    cout << endl;

    int val1, val2;
    cin >> val1 >> val2;
    replaceVal(l1, val1, val2);
    replaceVal(l2, val1, val2);

    join2List(l1, l2);
    print(l1);
}