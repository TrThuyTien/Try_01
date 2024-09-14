/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

// Cấu trúc của một node
struct NODE {
	int info;
	NODE* pNext;
};
// Cấu trúc của một DSLK
struct LIST {
	NODE* pHead;
	NODE* pTail;
};

//###INSERT CODE HERE -

NODE* createNode (const int& val) {
    NODE *node = new NODE;
    node->info = val;
    node->pNext = nullptr;
    return node;
}

void CreateEmptyList (LIST& l) {
    l.pHead = nullptr;
    l.pTail = nullptr;
}

void addTail (LIST& l, const int& val) {
    NODE *node = createNode(val);
    if (l.pHead == nullptr) {
        l.pHead = node;
        l.pTail = node;
    } else {
        l.pTail->pNext = node;
        l.pTail = node;
    }
}

void CreateList (LIST& l) {
    int val;
    do {
        cin >> val;
        if (val == -1) break;
        addTail(l, val);
    } while (true);
}

void Reverse_LinkedList (LIST& l) {
    if (l.pHead == nullptr) return;
    int val = l.pHead->info;
    NODE *headNode = createNode(val);
    NODE *preNode = nullptr;
    NODE *curNode = l.pHead;
    int i = 0;
    while (curNode != nullptr) {
        int x = curNode->info;
        curNode = curNode->pNext;
        NODE *temp = createNode(x);
        if (preNode == nullptr) {
            preNode = temp;
            preNode->pNext = nullptr;
        } else {
            temp->pNext = preNode;
            preNode = temp;
        }
    }
    l.pHead = preNode;
    l.pTail = headNode;
}

void PrintList(const LIST &L)  {
	NODE* p;

	if (L.pHead == NULL)
		cout << "Empty List.";
	else {
		p = L.pHead;
		while (p) {
			cout << p->info << " ";
			p = p->pNext;
		}
	}
}

int main() {
    LIST L;

	CreateEmptyList(L);
	CreateList(L);

	Reverse_LinkedList(L);

	PrintList(L);

    return 0;
}
