/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

//###INSERT CODE HERE -

#include <iostream>
#include <string>

using namespace std;

struct NODE {
    int data;
    NODE *next;
};

NODE* createNode (const int& val) {
    NODE *node = new NODE();
    node->data = val;
    node->next = NULL;
    return node;
}

void addTail (NODE *&head, int& val) {
    NODE *node = createNode(val);
    if (head == NULL) {
        head = node;
    } else {
        NODE *curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = node;
    }
}

void CreateList (NODE *&head) {
    int val;
    do {
        cin >> val;
        if (val == -1) break;
        addTail(head, val);
    } while (true);
}

string searchX (NODE *&head, const int& x) {
    NODE *curr = head;
    while (curr != NULL) {
        if (curr->data == x) return "true";
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
