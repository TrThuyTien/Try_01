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

void addTailList (List &l, const int& val) {
    Node *node = createNode(val);
    if (l.head == nullptr) {
        l.head = node;
        l.tail = l.head;
    } else {
        l.tail->next = node;
        l.tail = node;
    }
}

void reverseList (List &l) {
    Node *curNode = l.head;
    int sizeList = 0;
    while (curNode != nullptr) {
        sizeList++;
        curNode =curNode->next;
    }
    int i = 1;
    curNode = l.head;
    Node *preNode = nullptr;
    while (i <= sizeList) {
        Node *temp = createNode(curNode->data);
        if (i == 1) preNode = temp;
        else {
            temp->next = preNode;
            preNode = temp;
        }
        curNode = curNode->next;
        i++;
    }
    l.head = preNode;
}

void printList(const List& l) {
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
    freopen ("ReverseLinkedList.inp", "r", stdin);
    freopen ("ReverseLinkedList.out", "w", stdout);
    List l;
    int val;
    do {
        cin >> val;
        if (val == -1) break;
        addTailList(l, val);
    } while (true);
    reverseList(l);
    printList(l);
}