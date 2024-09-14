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
    NODE *pHead, *pTail;
};

struct HASHTABLE {
    int M; // Kich thuoc bang bam
    int n; // so phan tu hien tai trong bang bam
    LIST *table;
};

int HF(HASHTABLE ht, int key) { return key % ht.M; }

//###INSERT CODE HERE -

NODE* CreateNode (int key) {
    NODE* p = new NODE;
    if (p == NULL) exit(1);
    p->key = key;
    p->pNext = NULL;
    return p;
}

void CreateList(LIST& L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

void InsertList(LIST& l, int key) {
    NODE* node = CreateNode(key);
    if (l.pHead == NULL) {
        l.pHead = node;
        l.pTail = node;
    } else {
        l.pTail->pNext = node;
        l.pTail = node;
    }
}

void Insert(HASHTABLE& H, int key) {
    int i = HF(H, key);
    H.n++;
    InsertList(H.table[i], key);
}

void CreateHashTable(HASHTABLE& H) {
    cin >> H.M;
    H.table = new LIST[H.M];
    for (int i = 0; i < H.M; i++) {
        CreateList(H.table[i]);
    }
    int key;
    do {
        cin >> key;
        if (key == -1) break;
        Insert(H, key);
    } while (true);
}

void Traverse(HASHTABLE H) {
    for (int i = 0; i < H.M; i++) {
        cout << i;
        LIST L = H.table[i];
        NODE* curr = L.pHead;
        while (curr != NULL) {
            cout << " --> " << curr->key;
            curr = curr->pNext;
        }
        cout << endl;
    }
}

int main(){
    HASHTABLE H;
    CreateHashTable(H);
    Traverse(H);

    return 0;
}
