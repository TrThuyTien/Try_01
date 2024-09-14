#include<iostream>
#include<string>

using namespace std;

struct Node {
    int key;
    Node *next;
};

struct List {
    Node *head, *tail;
    int sl;
};

struct HashTable {
    int M;
    int n;
    List *table;
};

Node *CreateNode(int x) {
    Node *p = new Node;
    if (p == NULL) exit(1);
    p->key = x;
    p->next = NULL;
    return p;
}

void addTail(List& L, int x) {
    L.sl++;
    Node *p = CreateNode(x);
    if (L.head == NULL) {
        L.head = p;
        L.tail = p;
    } else {
        L.tail->next = p;
        L.tail = p;
    }
}

int HF(HashTable H, int key) {
    return key % H.M;
}

void Insert(HashTable &H, int x) {
    int i = HF(H, x);
    addTail(H.table[i], x);
}

int main () {
    freopen("Bai04.inp", "r", stdin);
    HashTable H;
    cin >> H.n >> H.M;
    H.table = new List[H.M];
    for (int i = 0; i < H.M; i++) {
        H.table[i].head = NULL;
        H.table[i].tail = NULL;
        H.table[i].sl = 0;
    }
    bool check = false; // kt dung do;
    for (int i = 0; i < H.n; i++) {
        int x;
        cin >> x;
        Insert(H, x);
    }
    for (int i = 0; i < H.M; i++) {
        if (H.table[i].sl >= 5) {
            check = true;
            break;
        }
    }
    if (check == true) cout << "BAD\n";
    else cout << "GOOD\n";
}