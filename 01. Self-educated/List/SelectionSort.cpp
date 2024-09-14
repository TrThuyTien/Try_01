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

Node* createNode (const int &val) {
    Node *node = new Node;
    node->data = val;
    node->next = nullptr;
    return node;
}

void addTailList (List& l, const int& val) {
    Node *node = createNode(val);
    if (l.head == nullptr) {
        l.head = node;
        l.tail = l.head;
    } else {
        l.tail->next = node;
        l.tail = node;
    }
}

void Input (List& l, int &n) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        addTailList(l, val);
    }
}

void selectionSort (List &l) {
    Node *iNode = l.head;
    while (iNode != nullptr) {
        Node *maxNode = iNode;
        Node *jNode = iNode->next;
        while (jNode != nullptr) {
            if (maxNode->data < jNode->data) 
                maxNode = jNode;
            jNode = jNode->next;
        }
        swap(iNode->data, maxNode->data);
        iNode = iNode->next;
    }
}

void print (const List& l) {
    if (l.head == nullptr) return;
    Node *node = l.head;
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
}

void Output(const List& l, const int& n) {
    cout << n << '\n';
    if (n) print(l);
} 

int main () {
    freopen ("SelectionSort.inp", "r", stdin);
    freopen ("SelectionSort.out", "w", stdout);
    int n;
    List l;
    Input (l, n);
    selectionSort(l);
    Output(l, n);
}