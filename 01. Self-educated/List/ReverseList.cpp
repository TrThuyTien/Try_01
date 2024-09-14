#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {};
};

struct linkedList {
    Node *head;
    Node *tail;
    linkedList() : head(nullptr), tail(nullptr) {};
};

void addList(linkedList &l, int init_data) {
    Node *p = new Node;
    p->data = init_data;
    if (l.head == nullptr) {
        l.head = p;
        l.tail = p;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}

void printList(linkedList l) {
    Node *p = l.head;
    while(p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
}

void printList(Node *l) {
    Node *p = l;
    while(p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
}

Node *reverseList(Node *l) {
    Node *pre = nullptr;
    Node *curr = l;
    Node *t = l->next;
    while(curr != nullptr) {
        Node *temp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = temp;
    }
    l->next = t;
    return pre;
}

int main() {
    freopen("ReverseList.inp", "r", stdin);
    freopen("ReverseList.out", "w", stdout);
    linkedList list;
    int x;
    while(cin >> x) {
        addList(list, x);
    }
    Node *head = list.head;
    Node *newList = reverseList(head);
    printList(newList);
    cout << endl;
    printList(head);
    int ans = 0;
    // while(newList != nullptr) {
    //     ans = max(ans, newList->data + head->data);
    //     head = head->next;
    //     newList = newList->next;
    // }
}