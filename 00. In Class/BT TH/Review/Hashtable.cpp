#include<iostream>

using namespace std;

struct Node {
    int key;
    Node *next;
};

struct List {
    Node *head, *tail;
};

struct HashTable {
    int M;
    int N;
    List* table;
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

void addTail(List& L, int x) {
    if (L.head == NULL) {
        L.head = NULL;
        L.tail = NULL;
    } else {
        L.tail->next = p;
        L.tail = p;
    }
}

#define LOAD 0.7

int HashFunction (HashTable H, int key) {
    return key % H.M;
}

int Insert(HashTable &H, int x) {
    if (float(H.N + 1) / float(H.M) <= LOAD) {
        int i = HashFunction(H, x);
        Insert(H.table[i], x);
        return 1;
    } 
    return 0;
}

void PrintHashtable(Hashtable);
void DeleteHashtable(Hashtable &);


void CreateHashTable(HashTable& H) {
    int n;
    cin >> n;
    H.M = 1001;
    H.table = new List[H.M];
    for (int)
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Insert(H, x);
    }
}
int main () {
    HashTable H;

}