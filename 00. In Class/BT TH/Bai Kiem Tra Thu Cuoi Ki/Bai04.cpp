#include <iostream>
#include <map>

using namespace std;

struct NODE {
    int key;
    NODE *next;
    NODE() : key(0), next(NULL) {}
};

struct LIST {
    NODE *head, *tail;
    LIST() : head(NULL), tail(NULL) {}
};

struct HASHTABLE {
    int M;
    int N;
    LIST *table;
};

NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == NULL) exit(1);
    p->key = x;
    p->next = NULL;
    return p;
}

void CreateEmptyList(LIST& L) {
    L.head = NULL;
    L.tail = NULL;
}

void AddTail(LIST& L, int x) {
    NODE* p = CreateNode(x);
    if (L.head == NULL) {
        L.head = p;
        L.tail = p;
    } else {
        L.tail->next = p;
        L.tail = p;
    }
}

float LOAD;

int HashFunction(HASHTABLE& H, int key) {
    return key % H.M;
}

void Insert(HASHTABLE& H, int x) {
    if (float(H.N + 1) / float(H.M) <= LOAD) {
        H.N++;
        int i = HashFunction(H, x);
        AddTail(H.table[i], x);
    }
}

int Search(HASHTABLE H, int x) {
    int i = HashFunction(H, x);
    NODE *curr = H.table[i].head;
    int cnt = 0;
    while (curr != NULL) {
        cnt++;
        if (curr->key == x) return cnt;
        curr = curr->next;
    }
    return -1;
}

int main () {
    freopen ("Bai04.inp", "r", stdin);
    freopen ("Bai04.out", "w", stdout);
    HASHTABLE H;
    int n;
    cin >> H.M >> LOAD >> n;
    H.table = new LIST[H.M];
    H.N = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        Insert(H, x);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int id = Search(H, x);
        if (id == -1) cout << "KHONG\n";
        else cout << id << "\n";
    }
}