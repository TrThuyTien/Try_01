/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/


#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct Node {
    int data;
    Node *next;
    Node () : data(0), next(nullptr) {};
};

struct LIST {
    Node *head;
    Node *tail;
};

void CreateEmptyList(LIST& l) {
    l.head = nullptr;
    l.tail = nullptr;
}

Node *createNode (const int& val) {
    Node *node = new Node;
    node->data = val;
    node->next = nullptr;
    return node;
}

void addHead (LIST& l, const int& val) {
    Node *node = createNode(val);
    if (l.head == nullptr) {
        l.head = node;
        l.tail = node;
    } else {
        node->next = l.head;
        l.head = node;
    }
}

void CreateList (LIST& l) {
    int val;
    do {
        cin >> val;
        if (val == -1) break;
        addHead(l, val);
    } while (true);
}

int length (const LIST& l) {
    if (l.head == nullptr) return 0;
    int n = 0;
    Node *curr = l.head;
    while (curr != nullptr) {
        n++;
        curr = curr->next;
    }
    return n;
}

int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);

    cout << length(L);

    return 0;
}
