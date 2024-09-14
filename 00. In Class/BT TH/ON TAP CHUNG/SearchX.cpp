/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

//###INSERT CODE HERE -
#include <iostream>
#include <string>

using namespace std;

struct NODE {
    int key;
    NODE* next;
    NODE() : key(0), next(NULL) {}
};

NODE* CreateNode(int x) {
    NODE *p =  new NODE;
    if (p == NULL) exit(1);
    p->key = x;
    p->next = NULL;
    return p;
}

void addTail(NODE* &pHead, int x) {
    if (pHead == NULL) {
        pHead = CreateNode(x);
    } else {
        NODE* curr = pHead;
        while (curr->next != NULL) 
            curr = curr->next;
        curr->next = CreateNode(x);
    }
}

void CreateList(NODE* &pHead) {
    int x;
    do {
        cin >> x;
        if (x == -1) break;
        addTail(pHead, x);
    } while (1);
}

string searchX(NODE* pHead, int x) {
    NODE* curr = pHead;
    while (curr != NULL) {
        if (curr->key == x) return "true";
        curr = curr->next;
    }
    return "false";
}

int main() {
    NODE* pHead;
	int X;
	pHead=NULL;

	CreateList(pHead);
	std::cin >> X;
	cout << searchX(pHead, X);

    return 0;
}
