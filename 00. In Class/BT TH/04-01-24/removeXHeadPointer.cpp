/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

//###INSERT CODE HERE -
#include <iostream>

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

void CreateEmptyList (NODE *&head) {
    head = nullptr;
}

void CreateList (NODE *&head) {
    int val;
    do {
        cin >> val;
        if (val == -1) break;
        addTail(head, val);
    } while (true);
}

void RemoveX (NODE *&head, const int& x) {
    if (head == nullptr) return;
    NODE *preNode = nullptr;
    NODE *curNode = head;
    if (curNode->data == x) {
        head = head->next;
        return;
    }
    while (curNode != nullptr) {
        if (curNode->data == x) {
            NODE *temp = curNode;
            preNode->next = curNode->next;
            temp->next = nullptr;
            delete temp;
            break;
        } else {
            preNode = curNode;
            curNode = curNode->next;
        }
    }
}

void PrintList (NODE *&head) {
    if (head == nullptr) {
        cout << "Empty List.";
        return ;
    }
    NODE *curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
} 

int main() {
   	NODE* pHead;
	int X;
	CreateEmptyList(pHead);

	CreateList(pHead);
	std::cin >> X;
	RemoveX(pHead, X);
    PrintList(pHead);

    return 0;
}
