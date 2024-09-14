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

Node *createNode (const int& val) {
    Node *node = new Node;
    node->data = val;
    node->next = nullptr;
    return node;
}

void addTailList (List& l, const int& val) {
    Node *node = createNode(val);
    if (l.head == nullptr) {
        l.head = node;
        l.tail = node;
    } else {
        l.tail->next = node;
        l.tail = node;
    }
}

void zigzagList (List& l) {
    bool flag = true;
    Node *curNode = l.head;
    while (curNode != nullptr) {
        if (curNode->next != nullptr) {
            if ((flag ^ (curNode->data < curNode->next->data))) {
                int temp = curNode->data;
                curNode->data = curNode->next->data;
                curNode->next->data = temp;
            }
        }
        curNode = curNode->next;
        flag = !flag;
    }
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
    freopen ("ZigZagList.inp", "r", stdin);
    freopen ("ZigZagList.out", "w", stdout);
    List l;
    int val;
    do {
        cin >> val;
        if (val == -1) break;
        addTailList(l, val);
    } while (true);
    zigzagList(l);
    printList(l);
}