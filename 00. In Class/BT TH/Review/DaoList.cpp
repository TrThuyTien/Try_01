#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *next;
};

struct List {
    Node *head, *tail;
};

Node* CreateNode(int x) {
    Node* p = new Node;
    if (p == NULL) exit(1);
    p->key = x;
    p->next = NULL;
    return p;
}

void CreateEmptyList(List& L) {
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
    }while (1);
}

void ReverseList(List &L) {
    Node *pre = NULL;
    Node *curr = L.head;
    Node *tail = CreateNode(L.head->key);
    while (curr != NULL) {
        Node *temp = CreateNode(curr->key);
        temp->next = pre;
        pre = temp;
        curr = curr->next;
    }
    L.head = pre;
    L.tail = tail;
}

void RemoveHead(List &L) {
    if (L.head == NULL) return;
    Node* p = L.head;
    L.head = p->next;
    if (p == L.tail) L.tail = NULL;
    delete p;
}

void RemoveAfter(List &L, Node *q) {
    if (q == L.head) RemoveHead(L);
    else {
        Node *p = q->next;
        q->next = p->next;
        if (p == L.tail) L.tail = q;
        delete p;
    }
}
void PrintList(List L) {
    if (L.head == NULL) {
        cout << "Empty List.";
        return;
    }
    Node *curr = L.head;
    while (curr != NULL) {
        cout << curr->key << " ";
        curr = curr->next;
    }
}

int main () {
    freopen("DaoList.inp", "r", stdin);
    List L;
    CreateEmptyList(L);
    CreateList(L);
    ReverseList(L);
    PrintList(L);
}