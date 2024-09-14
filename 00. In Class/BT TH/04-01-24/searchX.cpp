/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
#include <string>

struct Node {
    int data;
    Node *next;
    Node () : data(0), next(nullptr) {};
};

struct LIST {
    Node *pHead;
    Node *pTail;
};

void CreateEmptyList (LIST& l) {
    l.pHead = nullptr;
    l.pTail = nullptr;
} 

Node* createNode (const int& val) {
    Node* node = new Node;
    node->data = val;
    node->next = nullptr;
    return node;
}

void addTail (LIST& l, const int& val) {
    Node* node = createNode(val);
    if (l.pHead == nullptr) {
        l.pHead = node;
        l.pTail = node;
    } else {
        l.pTail->next = node;
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

string searchX(Node *curr, const int& x) {
    while (curr != nullptr) {
        if (curr->data == x) return "true";
        curr = curr->next;
    }
    return "false";
}

int main() {
    LIST L;
	int X;
	CreateEmptyList(L);

	CreateList(L);
	std::cin >> X;
	cout << searchX(L.pHead, X);

    return 0;
}
