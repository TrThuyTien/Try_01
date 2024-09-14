/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

//###INSERT CODE HERE -
#include <iostream>

using namespace std;

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

void addTail (LIST& l, const int& val) {
    Node *node = createNode(val);
    if (l.head == nullptr) {
        l.head = node;
        l.tail = node;
    } else {
        l.tail->next = node;
        l.tail = node;
    }
}

void CreateList (LIST& l) {
    int val;
    do {
        cin >> val;
        if (val == -1) break;
        addTail(l, val);
    } while (true);
}

void RemoveHead(LIST& l) {
    if (l.head == nullptr) return;
    Node *temp = l.head;
    l.head = l.head->next;
    delete temp;
    if (l.head == nullptr) l.tail == nullptr;
}

void PrintList (const LIST& l) {
    if (l.head == nullptr) {
        cout << "Empty List.";
        return;
    }
    Node *curr = l.head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
	RemoveHead(L);
    PrintList(L);

    return 0;
}
