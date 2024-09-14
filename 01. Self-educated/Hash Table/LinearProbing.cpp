#include <iostream>
#define M 10

using namespace std;

struct NODE {
    int key;
    NODE* next;
    NODE () : key(0), next(nullptr) {};
};

typedef NODE* NODEPTR;

NODEPTR H[M];

// Create Node
NODE* CreateNode (int x) {
    NODE* p = new NODE;
    if (p == nullptr) exit(1);
    p->key = x;
    p->next = nullptr;
    return p;
}

// Initiation hash table
void InitHashTable () {
    for (int i = 0; i < M; i++) 
        H[i] = nullptr;
}

// Hash function
int HashFunction (int key) {
    return key % M;
}

// Check Empty(int), Empty()
bool Empty (int i) {
    return (H[i] == nullptr ? 1 : 0);
}

bool Empty () {
    for (int i = 0; i < M; i++) 
        if (H[i] != nullptr) return false;
    return true;
}

// Insert
void InsertList(NODE* &L, int key) {
    NODE* node = CreateNode(key);
    node->next = L;
    L = node;
}

void Insert (int key) {
    int i = HashFunction(key);
    
    InsertList(H[i], key);
}
// Search
bool Search (int key) {
    int i = HashFunction(key);
    NODE* curr = H[i];
    while (curr != nullptr) {
        if (curr->key == key) return true;
        curr = curr->next; 
    }
    return false;
}

// Remove

void Remove (int key) {
    
}
// Print hash table
void TraverseHashTable () {
    for (int i = 0; i < M; i++) {
        NODE* curr = H[i];
        while (curr != nullptr) {
            cout << curr->key << " ";
            curr = curr->next;
        }
        cout << endl;
    }
}

int main () {
    freopen ("LinearProbing.inp", "r", stdin);
    freopen ("LinearProbing.out", "w", stdout);
    InitHashTable();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        Insert(key);
    }
    cout << boolalpha << Search(4) << endl;
    TraverseHashTable();
}