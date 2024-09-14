/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <cstdlib>
#include <ctime>
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

NODE* CreateNode(int x) {
	NODE* p;
	p = new NODE;
	//if (p == NULL)
    //		exit(1);

	p->info = x;
	p->pNext = NULL;
	return p;
}
void AddTail(LIST &L, NODE* p) {
	if (L.pHead == NULL) {
		L.pHead = p;
		L.pTail = L.pHead;
	}
	else {
		L.pTail->pNext = p;
		L.pTail=p;
    }
}

void CreateEmptyList(LIST &L) {
	L.pHead = NULL;
	L.pTail = NULL;
}
void CreateList(LIST &L) {
	NODE* p;
	int x, n;
    cin >> n; // Số lượng phần tử của danh sách
	while (n-->0) {
		cin >> x;
		p = CreateNode(x);
		AddTail(L, p);
	}
}
//###INSERT CODE HERE -
void SeparateHead (LIST& l) {
    if (l.pHead == NULL) return;
    cout << l.pHead->info << '\n';
    l.pHead = l.pHead->pNext;
    if (l.pHead == NULL) l.pTail = NULL; 
}


void PrintList(NODE* p) {
	if (p == NULL)
		cout << "Empty List.";
	else {
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
    SeparateHead(L);
    PrintList(L.pHead);

    return 0;
}
