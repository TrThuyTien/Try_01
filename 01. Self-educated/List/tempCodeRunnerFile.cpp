    if (sizeList < 3) return;
    int mid = sizeList / 2;
    if (sizeList & 1) mid++;
    delete curNode;
    curNode = l.head;
    cout << curNode->data;
    int i = 1;
    while (i < mid) {
        Node *temp = createNode(curNode->data);
        l.tail->next = temp;
        curNode = curNode->next;
        i++;
    }
    if (curNode == nullptr) cout << 'y';
    l.head = curNode;
    delete curNode;