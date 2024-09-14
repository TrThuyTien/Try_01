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
    NODE* nodeHead = l.pHead;
    NODE *preNode = nullptr;
    NODE *curNode = l.pHead;
    while (curNode != nullptr) {
        NODE *temp = new NODE();
        temp->info = curNode->info;
        if (preNode == nullptr) {
            temp->pNext = nullptr;
            preNode = temp;
        } else {
            temp->pNext = preNode;
            preNode = temp;
        }   
        curNode = curNode->pNext;
        delete temp;
    }
    l.pHead = preNode;
    // l.pTail = l.pHead;
    // l.pTail->pNext = nullptr;
}