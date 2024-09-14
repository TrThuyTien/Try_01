/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <string>

using namespace std;


struct NODE {
    int key;
    NODE *pNext;
};

struct LIST {
    NODE * pHead, *pTail;
};

struct HASHTABLE {
    int M; // Kich thuoc bang bam
    int n; // so phan tu hien tai trong bang bam
    LIST *table;
};

int HF(HASHTABLE ht, int key) { return key % ht.M; }

//###INSERT CODE HERE -
NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == NULL) exit(1);
    p->key = x;
    p->pNext = NULL;
    return  p;
}

void CreateList(LIST& L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

void addTail(LIST& L, int x) {
    NODE* p = CreateNode(x);
    if (L.pHead == NULL) {
        L.pHead = p;
        L.pTail = p;
    } else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void InsertKey(HASHTABLE& H, int x) {
    int i = HF(H, x);
    addTail(H.table[i], x);
    H.n++;
}

void CreateHashTable(HASHTABLE& H) {
    cin >> H.M;
    int x;
    H.table = new LIST[H.M];
    for (int i = 0; i < H.M; i++) {
        CreateList(H.table[i]);
    }
    do {
        cin >> x;
        if (x == -1) break;
        InsertKey(H, x);
    } while (true);
}

void printList(LIST& L) {
    if (L.pHead == NULL) return;
    NODE* curr = L.pHead;
    while (curr != NULL) {
        cout << " --> " << curr->key;
        curr = curr->pNext;
    }
}

void Traverse(HASHTABLE H) {
    for (int i = 0; i < H.M; i++) {
        cout << i ;
        if (H.table[i].pHead != NULL) printList(H.table[i]);
        cout << endl;
    }
}

int main(){
    HASHTABLE H;
    CreateHashTable(H);
    Traverse(H);

    return 0;
}
