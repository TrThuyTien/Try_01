#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node () : data(0), next(nullptr) {}
};

struct List {
    Node* head;
    Node* tail;
    List() : head(nullptr), tail(nullptr) {}
};

Node* CreateNode(int val) {
    Node* p = new Node;
    if (p == nullptr) 
        exit(1);
    p->data = val;
    p->next = nullptr;
    return p;
}

void CreateList(List&L) {
    L.head = nullptr;
    L.tail = nullptr;
}

void AddTail(List& L, int val) {
    Node* p = CreateNode(val);
    if (L.head == nullptr) {
        L.head = p;
        L.tail = p;
    } else {
        L.tail->next = p;
        L.tail = p;
    }
}

struct Hashtable {
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    List *table;
};

float LOAD;

int HashFunction(Hashtable h, int key) {
    return key % h.M;
}

int Insert(Hashtable& h, int key) {
    if (float(h.n + 1) / h.M <= LOAD) {
        int i = HashFunction(h, key);
        h.n++;
        AddTail(h.table[i], key);
        return 1;
    }
    return 0;
}

int Search(Hashtable h, int key) {
    int i = HashFunction(h, key);
    List L = h.table[i];
    Node* curr = L.head;
    int id = 1;
    while (curr != nullptr) {
        if (curr->data == key) return id;
        id++;
        curr = curr->next;
    }
    return -1;
}

int main () {
    // freopen ("TK_BangBamNoiKet.inp", "r", stdin);
    // freopen ("TK_BangBamNoiKet.out", "w", stdout);
    Hashtable hash;
    int n;
    cin >> hash.M; // Nhập kích thước phần tử
    cin >> LOAD; // Nhập hệ số tải
    cin >> n; // Nhập các tổng số phần tử
    hash.n = 0;
    hash.table = new List[hash.M];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Insert(hash, x);
    }
    cin >> n; // Nhập số lượng các khóa cần tìm
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        int id = Search(hash, key);
        if (id == -1) cout << "KHONG\n";
        else cout << id << '\n';
    }
}