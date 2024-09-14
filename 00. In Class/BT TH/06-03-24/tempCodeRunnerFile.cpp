int i = HF(H, key);
    int k = 0;
    do {
        i = HF_LinearProbing(H, key, k++);
        if (H.table[i].flag == 0) break;
        if (H.table[i].flag == 1 && H.table[i].username == key) {
            cout << H.table[i].password << '\n';
        }
    } while (k < H.M);