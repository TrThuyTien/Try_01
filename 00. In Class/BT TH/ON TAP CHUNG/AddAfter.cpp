/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
using namespace std;

//###INSERT CODE HERE -
#include <math.h>

struct NODE {
    int key;
    NODE* next;
};

struct LIST {
    NODE* head;
    NODE* tail;
};

NODE* CreateNode (int x) {
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

void addTail(LIST &L, int x) {
    NODE *p = CreateNode(x);
    if (L.head == NULL) {
        L.head = p;
        L.tail = p;
    } else {
        L.tail->next = p;
        L.tail = p;
    }
}

void addAfterQ(LIST &L, NODE* q, int x) {
    NODE* p = CreateNode(x);
    p->next = q->next;
    q->next = p;
} 

void CreateList(LIST &L) {
    int x;
    do {
        cin >> x;
        if (x == -1) break;
        addTail(L, x);
    } while(1);
}

bool checkPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    for (int  i = 2; i <= sqrt(n); i++) 
        if (n % i == 0) return false;
    return true;
}

void add_after_all_prime(LIST &L, int Y) {
    if (L.head == NULL) return;
    NODE* curr = L.head;
    while (curr != NULL) {
        if (checkPrime(curr->key)) {
            addAfterQ(L, curr, Y);
            curr = curr->next;
        } 
        curr = curr->next;
    }
}

void PrintList(LIST L) {
    if (L.head == NULL) {
        cout << "Empty List.";
        return;
    }
    NODE* curr = L.head;
    while (curr != NULL) {
        cout << curr->key << " ";
        curr = curr->next;
    }
}

int main() {
    LIST L;
	int Y;

	CreateEmptyList(L);

	CreateList(L);

	std::cin >> Y;
	add_after_all_prime(L, Y);

	PrintList(L);

    return 0;
}
