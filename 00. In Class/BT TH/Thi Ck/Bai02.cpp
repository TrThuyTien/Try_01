/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
]
###End banned keyword*/
#include <iostream>

using namespace std;


	
//###INSERT CODE HERE -

struct Node {
    int key;
    Node *next;
};

struct List {
    Node *head, *tail;
};

Node* CreateNode(int x) {
    Node *p = new Node;
    if (p == NULL) {
        exit(1);
    }
    p->key = x;
    p->next = NULL;
    return p;
}

void addTail(List& L, int x) {
    Node *p = CreateNode(x);
    if (L.head == NULL) {
        L.head = p;
        L.tail = p;
    } else {
        L.tail->next = p;
        L.tail = p;
    }
}

void CreateList(List& L, int n) {
    L.head = NULL;
    L.tail = NULL;
    int sl = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x >= 90 && sl < 10) {
            sl++;
            addTail(L, x);
        }
    }
}

void ReverseList(List& L) {
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

void PrintList(List L) {
    Node *curr = L.head;
    while (curr != NULL) {
        cout << curr->key << " ";
        curr = curr->next;
    }
    cout << "END\n";
}

int main () {
    freopen("Bai02.inp", "r", stdin);
    List L;
    int n;
    cin >> n;
    CreateList(L, n);
    ReverseList(L);
    PrintList(L);
}