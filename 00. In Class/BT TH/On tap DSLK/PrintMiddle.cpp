#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;
};

Node* CreateNode(int x) {
    Node* p = new Node;
    if (p == NULL) exit(1);
    p->key = x;
    p->next = NULL;
    return p;
}

void CreateEmptyList(List &L) {
    L.head = NULL;
    L.tail = NULL;
}

void addTail(List &L, int x) {
    Node* p = CreateNode(x);
    if (L.head == NULL) {
        L.head = p;
        L.tail = p;
    } else {
        L.tail->next = p;
        L.tail = p;
    }
}

void CreateList(List &L) {
    int x;
    do {
        cin >> x;
        if (x == -1) break;
        addTail(L, x);
    } while (1);
}

int sizeOfList(List &L) {
    int n = 0;
    Node* curr = L.head;
    while (curr != NULL) {
        n++;
        curr = curr->next;
    }
    return n;
}

int MiddleList(List &L) {
    int n = sizeOfList(L);
    Node* curr = L.head;
    int i = 0;
    int mid = n / 2;
    if (n & 1) mid++;
    while (i < mid) {
        i++;
        if (i < mid) curr = curr->next;
    }
    return curr->key;
}

int main () {
    List L;
    CreateEmptyList(L);
    CreateList(L);
    if (L.head == NULL) cout << "Empty List.";
    else cout << MiddleList(L);
}