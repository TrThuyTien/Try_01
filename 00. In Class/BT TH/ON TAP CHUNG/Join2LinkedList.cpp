/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct NODE {
    int key;
    NODE* next;
};

struct LIST {
    NODE* pHead;
    NODE* pTail;
};

NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == NULL) exit(1);
    p->key = x;
    p->next = NULL;
    return p;
}

void CreateEmptyList(LIST &L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

void AddTail(LIST &L, int x) {
    NODE* p = CreateNode(x);
    if (L.pHead == NULL) {
        L.pHead = p;
        L.pTail = p;
    } else {
        L.pTail->next = p;
        L.pTail = p;
    }
}

void CreateList_AddTail(LIST &L) {
    int x;
    do {
        cin >> x;
        if (x == -1) break;
        AddTail(L, x);
    } while(1);
}

LIST Join(LIST L1, LIST L2) {
    LIST L;
    CreateEmptyList(L);
    NODE* curr = L1.pHead;
    while (curr != NULL) {
        AddTail(L, curr->key);
        curr = curr->next;
    }
    curr = L2.pHead;
    while (curr != NULL) {
        AddTail(L, curr->key);
        curr = curr->next;
    }
    return L;
}

void Edit(LIST &L, int x, int y) {
    if (L.pHead == NULL) return;
    NODE* curr = L.pHead;
    while (curr != NULL) {
        if (curr->key == x) curr->key = y;
        curr = curr->next;
    }
}

void PrintList(NODE* L) {
    if (L == NULL) {
        cout << "Empty List.\n";
        return;
    }
    NODE* curr = L;
    while (curr != NULL) {
        cout << curr->key << " ";
        curr = curr->next;
    }
    cout << "\n";
}

int main() {
    LIST L, L1, L2;
	int X, Y;
	CreateEmptyList(L1);
	CreateEmptyList(L2);

	CreateList_AddTail(L1);
	CreateList_AddTail(L2);

	L=Join(L1, L2);
	cin >> X >> Y;
	Edit(L, X, Y);

	PrintList(L1.pHead);
    PrintList(L2.pHead);
    PrintList(L.pHead);

    return 0;
}
